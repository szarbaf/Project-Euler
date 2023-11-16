{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "provenance": [],
      "authorship_tag": "ABX9TyPGelDexg34PMg9iF0Xwpej",
      "include_colab_link": true
    },
    "kernelspec": {
      "name": "python3",
      "display_name": "Python 3"
    },
    "language_info": {
      "name": "python"
    }
  },
  "cells": [
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "view-in-github",
        "colab_type": "text"
      },
      "source": [
        "<a href=\"https://colab.research.google.com/github/szarbaf/Project-Euler/blob/master/utils_py.py\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "metadata": {
        "id": "oFsMkmWMIYHx"
      },
      "outputs": [],
      "source": [
        "from collections import Counter\n",
        "import math\n",
        "import itertools\n",
        "\n",
        "def get_digits(d):\n",
        "  out = []\n",
        "  while d != 0:\n",
        "    out.append(d % 10)\n",
        "    d //= 10\n",
        "  out.reverse()\n",
        "  return out\n",
        "# def is_permute\n",
        "def to_number(d):\n",
        "  out = 0\n",
        "  for i in d:\n",
        "    out = 10*out + i\n",
        "  return(out)\n",
        "\n",
        "def is_prime(d):\n",
        "  counter = 2\n",
        "  while counter <= math.sqrt(d):\n",
        "    if d % counter == 0:\n",
        "      return False\n",
        "    counter += 1\n",
        "\n",
        "  return True\n",
        "\n",
        "\n",
        "def is_permutation(a, b):\n",
        "  a_count = Counter(a)\n",
        "  b_count = Counter(b)\n",
        "\n",
        "  # import pdb\n",
        "  # pdb.set_trace()\n",
        "  if len(a_count) != len(b_count):\n",
        "    return False\n",
        "\n",
        "  for e, c in a_count.items():\n",
        "    # print(e, c, b_count[e])\n",
        "    if b_count[e] != c :\n",
        "      return False\n",
        "\n",
        "  return True\n",
        "\n",
        "def get_permutations(d):\n",
        "  return(itertools.permutations(d))\n"
      ]
    }
  ]
}