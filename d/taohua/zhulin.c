// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ȫ������ɫ���񹹳ɣ�����������֦��ɵ���ͤ��ͤ�Ϻ��д�š�����ͤ��
���֡�ͤ��������ȫ�Ƕ���֮��õ����ˣ��ֳ������ƹ⡣��֮ͤ�ಢ��������
�ô�����֦����̣�ֻ������������Ĺ�����������������ޱȡ�
LONG
	);
	 set("exits", ([
                "south" : __DIR__"tuqiu",
                "north" : __DIR__"zhulin2",
        ]));

         set("objects", ([
                 __DIR__"npc/yapu" : 2,
        ]));

	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
