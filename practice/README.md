# Practice course

This part of repository contains documentation and code, which are needed for a practice in a Laboratory of baryonic physics of High energy physics department of PNPI.

Practice is organized as a bunch o sessions followed by homeworks. At the end of the practice student reports are expected.

## Precursors
* **PNPI PhD course of statistics and data analysis** mainly to have a proper vocabular.
* **Python programming language**. Here are some documentation, tutorials as well as a couple of courses (in Russian):
  - Python documantation and tutorals https://docs.python.org/3/ ; 
  - More tutorials https://pythonprogramming.net/ ;
  - Прикладной Python, Технопарк, осень 2018: https://www.youtube.com/watch?v=oLN3-1UX0-A&list=PLrCZzMib1e9qM62lMXC90SiFy7-1-kAPJ&index=1 ;
  - Алгоритмы на Python 3 https://www.youtube.com/watch?v=KdZ4HF1SrFs ;
  - Практика программирования на Python 3 https://www.youtube.com/watch?v=fgf57Sa5A-A .

## Practice synopsis
  * **Setup session:** Introdution to:
    * **Git**
    * **Markdown**
    * **LaTeX**
    * **Probability distribution functions**
  * **Session 1:** On how to extract a signal.
    * Fitting a signal:
      - Chi-square and maximum likelyhood fits.
      - Extended and non-extended fits.
    * Uncertainty validation using Toy-Monte-Carlo.
    * Distributions for a signal and a background components:
      - Sideband subtruction;
      - Fit-in-bin technique;
      - _sPlot_ unfolding techinque.
  * **Session 2:** Cut-based techique.
    * How to find best requirements?
    * Are requirements optimal?
      - Fluctuations
      - Look elswhere effect
      - When to use signal for background rejection optimisations?
  * **Session 3:** Classification methods
  * **Session 4:** Boosting Decision Trees
  * **Session 5:** Neural Networks

## Software stack
 * **Ubuntu 18.04 LTS**, as operation system (possible _via_ VirtualBox).
 * **Ostap** for data analysis (default is a _conda_-way).
 * **CERN ROOT** will be used _via_ Ostap, but it has much better documentation.
 * **Git** to store code.
 * **Markdown**  way to style text on the web.
 * **LaTeX** to prepare report.

For details of instalation see **_man/_** in the root of repository.
