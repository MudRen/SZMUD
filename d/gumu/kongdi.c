// July 31,2000
// Code by April
// /gumu/kongdi.c

inherit ROOM;

void create()
{
        set("short","空地");

        set("long",@LONG
这是终南山山腰处的一块空地，地势平坦。北面一条小路直攀山壁而
上，通往是终南山主峰。南边一大片密林，只闻泉水叮咚，阵阵花香自林
中飘来，馨人心脾。一块石碑(shibei)立在当眼ㄦ处，一些青苔覆盖在上
面。往北是一条山路。往南有一条小径。
LONG);

        set("item_desc",(["shibei" : "

                        终南山古墓，
                        外人请止步。

\n",]));

        set("exits",([ "northup" : "/d/zhongnan/shanlu12",
                                "south" : __DIR__"milin0",
                      ])
           );
          set("cost",1);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}

