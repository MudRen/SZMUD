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
                "east" : __DIR__"zhulin3",
                "south" : __DIR__"zhulin",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
