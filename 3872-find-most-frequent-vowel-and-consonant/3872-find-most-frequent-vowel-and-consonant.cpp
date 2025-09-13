class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        auto isVowel = [](char c) {
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };
        int maxVowel = 0, maxConsonant = 0;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (isVowel(c)) {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }
        return maxVowel + maxConsonant;
    }
};



// class Solution {
// public:
//     int maxFreqSum(string s) {
//         int n  = s.length();
//         int maxfreVowel = 0;
//         int maxfreConconent = 0;

//         int ca=0,ce=0,ci=0,co=0,cu=0;
//         int cb=0,cc=0,cd=0,cf=0,cg=0,ch=0,cj=0,ck=0,cl=0,cm=0,cn=0,cp=0,cq=0,cr=0,cs=0,ct=0,cv=0,cw=0,cx=0,cy=0,cz=0;

//         for(int xi =0; xi<n; xi++){
//             if((s[xi]=='a') || (s[xi]=='e') || (s[xi]=='i') || (s[xi]=='o') || (s[xi]=='u')){
//                 if(s[xi] == 'a'){
//                     ca++;
//                     //return;
//                 }
//                 if(s[xi] == 'e'){
//                      ce++;
//                      //return;
//                 }
//                 if(s[xi] == 'i'){
//                      ci++;
//                      //return;
//                 }
//                 if(s[xi] == 'o'){
//                      co++;
//                      //return;
//                 }
//                 if(s[xi] == 'u'){
//                      cu++;
//                      //return;
//                 }
//             }
//             else{
//                 if(s[xi] == 'b'){
//                     cb++;
//                      //return;
//                 }
//                 if(s[xi] == 'c'){
//                      cc++;
//                      //return;
//                 }
//                 if(s[xi] == 'd'){
//                      cd++;
//                      //return;
//                 }
//                 if(s[xi] == 'f'){
//                      cf++;
//                      //return;
//                 }
//                 if(s[xi] == 'g'){
//                      cg++;
//                      //return;
//                 }
//                  if(s[xi] == 'h'){
//                     ch++;
//                      //return;
//                 }
//                 if(s[xi] == 'j'){
//                      cj++;
//                      //return;
//                 }
//                 if(s[xi] == 'k'){
//                      ck++;
//                      //return;
//                 }
//                 if(s[xi] == 'l'){
//                      cl++;
//                      //return;
//                 }
//                 if(s[xi] == 'm'){
//                      cm++;
//                      //return;
//                 }
//                  if(s[xi] == 'n'){
//                     cn++;
//                      //return;
//                 }
//                 if(s[xi] == 'p'){
//                      cp++;
//                      //return;
//                 }
//                 if(s[xi] == 'q'){
//                      cq++;
//                      //return;
//                 }
//                 if(s[xi] == 'r'){
//                      cr++;
//                      //return;
//                 }
//                 if(s[xi] == 's'){
//                      cs++;
//                      //return;
//                 }
//                  if(s[xi] == 't'){
//                     ct++;
//                      //return;
//                 }
//                 if(s[xi] == 'v'){
//                      cv++;
//                      //return;
//                 }
//                 if(s[xi] == 'w'){
//                      cw++;
//                      //return;
//                 }
//                 if(s[xi] == 'x'){
//                      cx++;
//                      //return;
//                 }
//                 if(s[xi] == 'y'){
//                      cy++;
//                      //return;
//                 }
//                 if(s[xi] == 'z'){
//                      cz++;
//                      //return;
//                 }
//             }
//         }
//     maxfreVowel = max(ca,ce,ci,co,cu);
//     maxfreConconent = max(cb,cc,cd,cf,cg,ch,cj,ck,cl,cm,cn,cp,cq,cr,cs,ct,cv,cw,cx,cy,cz);
        
//     return (maxfreVowel + maxfreConconent);
//     }
// };