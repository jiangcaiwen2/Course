

In this assignment you will practice putting together a simple image classification pipeline, based on the Perceptron and Softmax classifier. The goals of this assignment are as follows:

- understand the basic **Image Classification pipeline** and the data-driven approach (train/predict stages)
- understand the train/val/test **splits** and the use of validation data for **hyperparameter tuning**.
- develop proficiency in writing efficient **vectorized** code with numpy
- implement and apply a **Perceptron** classifier
- implement and apply a **Softmax** classifier
- implement and apply a **Two layer neural network** classifier
- understand the differences and tradeoffs between these classifiers

## Setup
You can follow the setup instructions [here](./setup.md).
Before you start coding, make sure you current work dir is in this folder `PartB-coding`, otherwise you can not import the modules normally.


### Download data:
Once you have the starter code (regardless of which method you choose above), you will need to download the CIFAR-10 dataset.
Run the following from the `assignment1` directory:

```bash
cd cs231n/datasets
./get_datasets.sh
```

### Start IPython:
After you have the CIFAR-10 data, you should start the IPython notebook server from the
`assignment1` directory, with the `jupyter notebook` command. 

If you are unfamiliar with IPython, you can also refer to CS231n
[IPython tutorial](http://cs231n.github.io/ipython-tutorial/).

### Some Notes

**NOTE 1:** There are `# *****START OF YOUR CODE`/`# *****END OF YOUR CODE` tags denoting the start and end of code sections you should fill out. Take care to not delete or modify these tags, or your assignment may not be properly graded.

**NOTE 2:** This year, the `assignment1` code has been tested to be compatible with python version `3.7` (it may work with other versions of `3.x`, but we won't be officially supporting them). You will need to make sure that during your virtual environment setup that the correct version of `python` is used. You can confirm your python version by (1) activating your virtualenv and (2) running `which python`.

**NOTE 3:** If you are working in a virtual environment on OSX, you may *potentially* encounter
errors with matplotlib due to the [issues described here](http://matplotlib.org/faq/virtualenv_faq.html). In our testing, it seems that this issue is no longer present with the most recent version of matplotlib, but if you do end up running into this issue you may have to use the `start_ipython_osx.sh` script from the `assignment1` directory (instead of `jupyter notebook` above) to launch your IPython notebook server. Note that you may have to modify some variables within the script to match your version of python/installation directory. The script assumes that your virtual environment is named `.env`.

### Q1: Implement a Softmax classifier (10 points)

The IPython Notebook **softmax.ipynb** will walk you through implementing the Softmax classifier.

### Q2: Implement a Perceptron classifier (25 points)

The IPython Notebook **perceptron.ipynb** will walk you through implementing the Softmax classifier.

### Q3: Two-Layer Neural Network (25 points)
The IPython Notebook **two\_layer\_net.ipynb** will walk you through the implementation of a two-layer neural network classifier.


### Submitting your work

**Important:** _Please make sure that the submitted notebooks have been run and the cell outputs are visible._

The submission poses no difference against a normal push to the github repo. We will assemble your assignments via Git Classroom's functionality. If you have any question about the git commands, refer to the manual or post on Piazza for help.