// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     string s;
//     getline(cin, s);

//     string sij, sji;

//     int len = s.length();

//     for (int i = 0; i < len - 1; i++)
//     {
//         for (int j = i + 1; i < len; i++)
//         {
//             sij = s[i].append(s[j]);
//             sji = s[j].append(s[i]);

//             if ((sij).compare(sji) < 0)
//             {
//                 swap(s[i], s[j]);
//             }
//         }
//     }

//     return 0;
// }