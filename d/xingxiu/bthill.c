// Code of ShenZhou
// room: /d/xingxiu/btroom
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "Сɽ��");
        set("long", @LONG
����һ��Сɽ�����Ӳݶ�����һ����һ��СϪ��ɽ��������������������
�졣��һ������û��ʲô���棬�������֪�ιʳ����������˱�����ҧ���Ĵ��ԡ�
LONG
        );
        set("exits", ([ 
	    "eastdown" : __DIR__"btroad",
        "west" : "/d/baituo/luanshi",
        ]));
        set("resource/water", 1);

        set("objects", ([ 
            CLASS_D("baituo")+"/ke" : 1,
            "/d/baituo/npc/snake" : 2,
         ]) );
        replace_program(ROOM);
	set("cost", 2);
        setup();
}

