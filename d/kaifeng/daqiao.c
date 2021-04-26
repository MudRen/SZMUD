//Room: /d/kaifeng/daqiao.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "大桥");
        set("long", @LONG
这里是开封府西门外大河桥。府河和南河夹城流过，呵护着这个充满
正义和公正之地。河水清新碧透，有几尾鱼儿在河里畅快的游着，几个小
孩在桥边嬉戏。东走就要到西城门，往西面就是一片被黄河冲刷之后的沙地。
LONG
        );

        set("exits", ([
                "east" : __DIR__"dadao",
                
  "west" : "/d/xixia/mszhou",
              ]));
        set("fjing", 1);
        set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}
