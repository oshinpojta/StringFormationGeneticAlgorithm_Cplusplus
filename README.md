# StringFormationGeneticAlgorithm_Cplusplus
Hi, I  am a undergrad. pursuing Btech. Mechatronics from Lovely Professional University , Jalandhar , India. This is my first ever step towards AI and machine learning. You can check out my other works soon.

*******Genetic Algorithm********

This works on the theory of evolution. In 3 steps.

Step 1 :: As the name suggests, if you look at the code firstly a sentence is given and a goal is initialized(the length of the sentence or string). Then from the gene pool (string of all the characters from a to z) , random characters are added to create a random population of strings. Then the population's fitness is evaluated as per the goal (by matching every individual sentence's each character's index to the given sentence's character (well actually that is being done simultaenously in my case). When fitness is evaluated , then the 2 fittest individual string sentences are mixed together (just as the evolution theory suggest). And that mixed sentence will be called as the child of the first 2 strings (or parent sentences).

Step 2 :: Next step is creating a few more population of childs actually with all the first 60%-70% fittest valued sentences in order to create next generation of individuals to compete or can say another array of sentences to evaluate. Here to provide some probability to how the next generation is selected ... first 20% strings should be from the fittest of the strings that seems closer to the sentence needed. next 60% should be selected from some top other strings along with the first 2 to create some diversity (why its necessary? because there could be anytime soon some characters from that less fitted strings could complete the senetence). I used random function along with giving few numbers to each candidate string sentences in order to get selected with some probablity (ofcourse probability to the fittest parents are given higher so that they are most likely to get selected but also a chance is to be given to others).

Step 3 :: Now that the new generation is formed , they are now the parents generation and now similar process will be required. They also need to be evaluated and a while loop or goto statements as a loop can be added so that it should only stop when a goal is reached (when all the characters of the sentence are correctly added that will be the goal). I think thats all there is to it.

For more queries related to the program, contact me on facebook(Oshin Pojta) or gmail (sujanian785@gmail.com).
Thank You!
