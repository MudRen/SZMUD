// Code of ShenZhou
// Room: /d/dali/ziliu1.c

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǵ���߹ٸ���,ͥԺ����̫��.�����Ǵ���,������ֲ�������軨,
��֦ïʢ.
LONG
        );
       
        set("exits", ([ /* sizeof() == 2 */
                "north" : __DIR__"wangfu1.c",       
                "west" : __DIR__"ziliu2.c",
                ]));

        
        set("no_clean_up", 0);
        set("wangfu", 1);

        setup();
}
