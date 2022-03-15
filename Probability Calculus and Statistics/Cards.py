import random

# Create suits
diamonds = ["Diamonds Ace", "Diamonds 2", "Diamonds 3", "Diamonds 4", "Diamonds 5", "Diamonds 6", "Diamonds 7", "Diamonds 8", "Diamonds 9", "Diamonds 10", "Diamonds Jack", "Diamonds Queen", "Diamonds King"]
clubs = ["Clubs Ace", "Clubs 2", "Clubs 3", "Clubs 4", "Clubs 5", "Clubs 6", "Clubs 7", "Clubs 8", "Clubs 9", "Clubs 10", "Clubs Jack", "Clubs Queen", "Clubs King"]
hearts = ["Hearts Ace", "Hearts 2", "Hearts 3", "Hearts 4", "Hearts 5", "Hearts 6", "Hearts 7", "Hearts 8", "Hearts 9", "Hearts 10", "Hearts Jack", "Hearts Queen", "Hearts King"]
spades = ["Spades Ace", "Spades 2", "Spades 3", "Spades 4", "Spades 5", "Spades 6", "Spades 7", "Spades 8", "Spades 9", "Spades 10", "Spades Jack", "Spades Queen", "Spades King"]

# Counter for how many times clubs occurred and how many attempts were there
clubs_occurred = 0
attempts = 0
probability = 1

while (probability != 0.587):
    # Generate deck
    all_cards = diamonds + clubs + hearts + spades
    card_from_clubs = 0

    # Take 3 random cards
    for i in range(3):
        random_number = round(random.uniform(0, len(all_cards) - 1), 0)
        taken_card = all_cards[int(random_number)]
        all_cards.remove(taken_card)
        if taken_card.__contains__("Clubs"):
            card_from_clubs += 1

    attempts += 1
    if card_from_clubs != 0:
        clubs_occurred += 1

    probability = round(clubs_occurred / attempts, 3)

    # Lifebuoy if probability will not hit desired value after many attempts
    if attempts == 1000:
        print("Sorry, try again.")
        exit()

print("Probability achieved after " + str(attempts) + " takes.")
