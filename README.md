# i3keybinder
i3keybinder is a very small, very fast TUI utility designed to aid with i3 
keybindings. Usually, it's quite a pain to manually write everything in the 
i3 configuration file so this application is designed to easen that burden.

## Getting Started

It's quite simple to get started. Clone the repository and install the tool. 
When you do, you'll be presented with an intuitive interface which will aid 
you in writing those pesky keybindings.

### Prerequisites

Not much is needed for this software: `gcc`, `autotools`, and `uthash`.

### Installing

```bash
git clone git@github.com:markovejnovic/i3keybinder.git
cd i3keybinder
autoreconf -vfi
./configure
make
sudo make install
```

This project is licensed under the GNU GPLv3 - see the [LICENSE](LICENSE) file for details

## Acknowledgments

* Just [PurpleBooth](https://github.com/PurpleBooth) for showing me how to make a [good README.md](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2) file.


