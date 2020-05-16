# Setup session

## Git

## Markdown
To prepare documentation for repositories it's preferable to use [Markdown](https://daringfireball.net/projects/markdown/). As author said, “Markdown” is two things:
  1. A plain text formatting syntax;
  2. A software tool, written in Perl, that converts the plain text formatting to HTML.
We will use the first, as the second is already implemented all over the web. 

Lets follow github guide to see how easy Markdown formating is:
  * https://guides.github.com/features/mastering-markdown/

## Basica of statistics
Here we will discuss:
  * Measurements and uncertainties;
  * Probability distribution functions and their basic pproperties;
  * Three special distributions:
    - Binomial
    - Poisson
    - Gaussian

Let's follow an introduction lecture by [Prof. Mark Thompson](https://www.hep.phy.cam.ac.uk/~thomson/lectures/lectures.html):
  * https://www.hep.phy.cam.ac.uk/~thomson/lectures/statistics/Introduction_Handout.pdf

## Python3

In python3 a basic statistics is impemented into a standard library as a special module, which  provides functions for calculating statistics of data, including averages, variance, and standard deviation.

```python
import statistics as stat
help(stat) # press q to exit back into command line
```

More functionality is provided by special module entering [scipy](https://docs.scipy.org/doc/scipy/reference/) open-source software for mathematics, science, and engineering. Here is a tutorial on **scipy.stats**:
  * https://docs.scipy.org/doc/scipy/reference/tutorial/stats.html

## ROOT, RooFit and Ostap

In our practice we use a three ([matryoshka](https://en.wikipedia.org/wiki/Matryoshka_doll) way packed) frameworks:
  * [ROOT](https://root.cern.ch/) - a modular scientific software toolkit. It provides all the functionalities needed to deal with big data processing, statistical analysis, visualisation and storage. It is mainly written in **C++** but integrated with other languages such as **Python** and **R**.
  * [RooFit](https://root.cern.ch/roofit-20-minutes) - is a package that allows for modeling probability distributions in a compact and abstract way. It is distributed with **ROOT**.
  * [Ostap](https://github.com/OstapHEP/ostap) - is a community-driven initiative aiming to provide more user friendly and more intuitive interface to **ROOT** and extending the existing functionality. It provides (as authors insist):
    - very easy manipulations with **ROOT** and **RooFit** objects: histograms, trees, datasets, _etc_;
    - very easy interface to **RooFit** machinery;
    - extended set of model (probability density functions) for **RooFit**;
    - powerful, pickle-based persistency for object;
    - interactive **ostap** analysis environment (which will be a default one for the practice).

## LaTeX

## Homework

### Task

Create a documentaion about one of special probability density function (requested by a teacher).

### Expected outcome
  * Document in pdf-format containig proper information 
  * Link to a git repository (_github_, _gitlab_, _bitbucket_ or whatsoever), which contains a source code for figures in the report. Repository must contain a documentation on what is going on. 