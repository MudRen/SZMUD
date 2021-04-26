//Cracked by snso k1-7-6
// Room: houshan1.c 后山

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "后山");
    set("long", @LONG
这里便是武馆的后山了，山腰周遭树木茂盛，鸟鸣声不绝与耳，一派
生机盎然的景象，清澈的溪流旁耸立着一座小亭子，潺潺溪水向西南流去
立足于山顶，风声猎猎，不断从耳边呼啸而过。居高临下，极目而望，可
以远眺四面八方，看尽山峦形势。
LONG
    );

    set("exits", ([
	"southwest" : __DIR__"xiaolu1",
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
       set("no_fight", 1);
       set("no_steal", 1);
       set("no_hit", 1);
    setup();
    //replace_program(ROOM);
}

