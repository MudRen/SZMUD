//Room: /d/kaifeng/xilin.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "���ֹ�");
        set("long", @LONG
���ֹ������µ�һ����ۡ�������ľ��涣��ڸ�ͤͤ���е�ʿ��
����ȥ��û�˵ÿ����㣬��û�˽Ӵ��㡣����õ�һ�ֿ��ɵ�ʧ�䡣
LONG
        );

        set("exits", ([
                
                "northeast":__DIR__"wroad2s",
                
              ]));

        setup();
        replace_program(ROOM);
}
