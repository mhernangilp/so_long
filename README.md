<h1 align="center">
	🎮 so_long
</h1>

<p align="center">
	<b><i>And thanks for all the fish!</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---
<p align="center">
	<img width="649" alt="screenshot" src="https://github.com/mhernangilp/so_long/assets/123759990/a3a19924-ebc2-4d51-bffb-bf140cd99363">
</p>


## 💡 About the project

> _This project is a very small 2D game.
Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements._

	It’s time for you to create a basic computer graphics project!
	so long will help you improve your skills in the following areas:
	window management, event handling, colors, textures, and so forth.
	You are going to use the school graphical library: the MiniLibX!
	This library was developed internally and includes basic necessary tools to open
	a window, create images and deal with keyboard and mouse events.
	The other goals are similar to every other goal for this first year:
	being rigorous, level up in C programming, use basic algorithms, do some
	information research, and so forth. 

For more detailed information, look at the [**subject of this project**](https://github.com/mhernangilp/so_long/blob/master/es.subject.solong.pdf).


## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile, go to the project path and run:

```shell
$ make
```

or

```shell
$ make bonus
```

If you want the player sprite to be animated and have enemies in the map.

## 📋 How to play

To play the minigame just need to launch it with the following shell command:

```shell
$ ./so_long <map_name>.ber
```

I added some maps if you want to test the game, there are located in:

```shell
$ maps/valid
```

**Controls**

You can use WASD to move UP, LEFT, DOWN or RIGHT respectively.
To quit the game press ESC or click on the red cross of window.
To win its necessary to pick up all collectibles and get back to the exit.

**Maps**

You can use any map of your choice as long as you follow the next rules:

* The file extension must be `.ber`.
* Its must be rectangular, and the whole map limits must be a `1`.
* It can only have one exit, one player and at least one collectible.
* Characters allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | Obstacle                 |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player starting position |
