#include<iostream>
#include<algorithm>
using namespace std;
struct item{
	int weight;
	int profit;
};

double Fknapsack(int capcity,item items[],int n){
	double ratio[n];
	for(int i=0;i<n;i++){
		ratio[i] = (double)items[i].profit / items[i].weight;
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(ratio[i]<ratio[j]){
				swap(ratio[i],ratio[j]);
				swap(items[i],items[j]);
			}
		}
	}
	
	double maxprofit=0.0;
	int currentweight=0;
	
	for(int i=0;i<n;i++){
		if(currentweight + items[i].weight<=capcity){
			currentweight += items[i].weight;
			maxprofit += items[i].profit;
		} else {
			int remainingcapcity = capcity - currentweight;
			maxprofit += ratio[i] * remainingcapcity;
			break;
		}
	}
	return maxprofit;
}
int main(){
	int n,capcity;
	cout<<"Enter the number of items: ";
	cin>>n;
	cout<<"Enter the capacity of the knapsack: ";
	cin>>capcity;
	item items[n];
	for(int i=0;i<n;i++){
		cout<<"Enter weight and profit for item "<< i + 1<<": ";
		cin>>items[i].weight>>items[i].profit;
	}
	
	double maxprofit = Fknapsack(capcity,items,n);
	cout<<"Maximum profit: " << maxprofit <<endl;
	return 0;
}



/*#include <iostream>
#include <algorithm>
using namespace std;

struct item {
    int weight;
    int profit;
};

bool compare(const item &a, const item &b) {
    double ratioA = (double)a.profit / a.weight;
    double ratioB = (double)b.profit / b.weight;
    return ratioA > ratioB; // Sort in descending order
}

double Fknapsack(int capacity, item items[], int n) {
    // Sort items based on profit-to-weight ratio
    sort(items, items + n, compare);
    
    double maxProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            maxProfit += items[i].profit;
        } else {
            int remainingCapacity = capacity - currentWeight;
            maxProfit += (double)items[i].profit / items[i].weight * remainingCapacity;
            break;
        }
    }
    return maxProfit;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    
    item items[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].profit;
    }
    
    double maxProfit = Fknapsack(capacity, items, n);
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}
*/
