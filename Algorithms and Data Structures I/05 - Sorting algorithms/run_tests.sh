# Build algorithms
make

echo "Bubble Sort"
echo -n "1k: "
./BubbleSort.x < testing_data/data_1k.txt
echo -n "5k: "
./BubbleSort.x < testing_data/data_5k.txt
echo -n "10k: "
./BubbleSort.x < testing_data/data_10k.txt
echo -n "25k: "
./BubbleSort.x < testing_data/data_25k.txt
echo -n "50k: "
./BubbleSort.x < testing_data/data_50k.txt
echo -n "75k: "
./BubbleSort.x < testing_data/data_75k.txt
echo -n "100k: "
./BubbleSort.x < testing_data/data_100k.txt
echo -n "500k: "
./BubbleSort.x < testing_data/data_500k.txt
echo ""

echo "Selection Sort"
echo -n "1k: "
./SelectionSort.x < testing_data/data_1k.txt
echo -n "5k: "
./SelectionSort.x < testing_data/data_5k.txt
echo -n "10k: "
./SelectionSort.x < testing_data/data_10k.txt
echo -n "25k: "
./SelectionSort.x < testing_data/data_25k.txt
echo -n "50k: "
./SelectionSort.x < testing_data/data_50k.txt
echo -n "75k: "
./SelectionSort.x < testing_data/data_75k.txt
echo -n "100k: "
./SelectionSort.x < testing_data/data_100k.txt
echo -n "500k: "
./SelectionSort.x < testing_data/data_500k.txt
echo ""

echo "Insertion Sort"
echo -n "1k: "
./InsertionSort.x < testing_data/data_1k.txt
echo -n "5k: "
./InsertionSort.x < testing_data/data_5k.txt
echo -n "10k: "
./InsertionSort.x < testing_data/data_10k.txt
echo -n "25k: "
./InsertionSort.x < testing_data/data_25k.txt
echo -n "50k: "
./InsertionSort.x < testing_data/data_50k.txt
echo -n "75k: "
./InsertionSort.x < testing_data/data_75k.txt
echo -n "100k: "
./InsertionSort.x < testing_data/data_100k.txt
echo -n "500k: "
./InsertionSort.x < testing_data/data_500k.txt
echo ""

# Clean folder
make clean