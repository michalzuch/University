import java.io.*;
import java.net.ConnectException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class PasswordCracker implements PasswordCrackerInterface {

    @Override
    public String getPassword(String host, int port) {
        Socket socket;
        BufferedReader bufferedReader;
        String schema = "";
        String guessedPassword = "Program";
        boolean found = false;
        try {
            socket = new Socket(host, port);
            bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String line;
            line = bufferedReader.readLine();
            PrintWriter printWriter;
            printWriter = new PrintWriter(socket.getOutputStream());
            printWriter.println(guessedPassword);
            printWriter.flush();
            line = bufferedReader.readLine();
            line = bufferedReader.readLine();
            String[] parts = line.split(" ");
            schema = parts[2];
            line = bufferedReader.readLine();
            while (!found) {
                try {
                    guessedPassword = generateRandomPassword(schema);
                    printWriter = new PrintWriter(socket.getOutputStream());
                    printWriter.println(guessedPassword);
                    printWriter.flush();
                    line = bufferedReader.readLine();
                    if (line.contains("OK")) {
                        found = true;
                        return guessedPassword;
                    }
                    if (line.contains("0")) {
                        break;
                    }
                } catch (IOException ignored) {
                }
            }
            int charactersFound = 0;
            int oldCharactersFound = charactersFound;
            int lastIndex = 0;
            while (!found) {
                try {
                    guessedPassword = generateSmartPassword(schema, charactersFound, lastIndex, guessedPassword);
                    lastIndex++;
                    printWriter = new PrintWriter(socket.getOutputStream());
                    printWriter.println(guessedPassword);
                    printWriter.flush();
                    line = bufferedReader.readLine();
                    String[] parts2 = line.split(" ");
                    charactersFound = Integer.parseInt(parts2[4]);
                    if (oldCharactersFound != charactersFound) {
                        lastIndex = 0;
                        oldCharactersFound = charactersFound;
                    }
                    if (line.contains("OK")) {
                        found = true;
                    }
                } catch (IOException ignored) {
                }
            }
        } catch (UnknownHostException exc) {
            System.out.println("Host " + host + " not known.");
        } catch (ConnectException exc) {
            System.out.println("Error while connecting to " + host);
        } catch (Exception ignored) {
        }
        return guessedPassword;
    }

    private String generateRandomPassword(String schema) {
        List<Character> slicedPasswordType = new LinkedList<>();
        for (char character : schema.toCharArray()) {
            slicedPasswordType.add(character);
        }
        StringBuilder generatedPassword = new StringBuilder();
        for (Character letter : slicedPasswordType) {
            Random rand = new Random();
            List<Character> characters = PasswordComponents.passwordComponents.get(letter);
            Character character = characters.get(rand.nextInt(characters.size()));
            generatedPassword.append(character);
        }
        return String.valueOf(generatedPassword);
    }

    private String generateSmartPassword(String schema, int charactersFound, int lastIndex, String guessedPassword) {
        List<Character> slicedPasswordType = new LinkedList<>();
        for (char character : schema.toCharArray()) {
            slicedPasswordType.add(character);
        }
        StringBuilder generatedPassword = new StringBuilder();
        generatedPassword = new StringBuilder(guessedPassword);
        List<Character> characters = PasswordComponents.passwordComponents.get(slicedPasswordType.get(charactersFound));
        Character character = characters.get(lastIndex);
        generatedPassword.replace(charactersFound, charactersFound + 1, String.valueOf(character));
        return String.valueOf(generatedPassword);
    }
}
