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
                "west" : __DIR__"zhulin2",
                "north" : __DIR__"tingyu",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
