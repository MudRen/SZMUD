// Code of ShenZhou
// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96
// Ryu 5/10/97

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����һ���ª��Сľ�ݣ���������أ����˾���ʮ�ֲ������
�ڻ谵�Ĺ����£��㿴��������һ��ʯͷ���ɵ�����(box)����
֪����ʲô�ô���
LONG
        );
        set("exits", ([
            "east" : __DIR__"tianroad2",
]));
        set("resource/grass", 1);
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("item_desc",([
                "box"         :       "һ���ײĴ�С�����ӣ�������������һЩѪ����\n",
        ]));
	
        set("cost", 3);
        setup();
//      replace_program(ROOM);
}
