// Code of ShenZhou
//GU MU FROM SANTA
//chongyangC.C

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
����������������ѧ�����ڣ��������һ��Сʯ�ң�ʯ����״��
�����أ�ǰխ�����Ϊ���Σ����߰�Բ������ȴ��������״���Ҷ�
ʯ�壨stone)�Ͽ�������㻨�Ʒ��ţ������������̳ɣ������ǳ��
���޹���
LONG
	);
	 set("exits", ([
		"north" : __DIR__"cyn",
		"south" : __DIR__"cys",
		"east"  : __DIR__"cye",
		"west"  : __DIR__"cyw",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
