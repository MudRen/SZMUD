// Code of ShenZhou
// Room: /d/newdali/shilin6.c

inherit ROOM;

void create()
{
	set("short", "���ˮ�ٲ�");
	set("long", @LONG
��ɽ��С·Խ���꣬����ׯ������Ұ��Լ�����������������
ˮ���ĺ�������ǰ������һƬ�µص�ǰ�ˣ����ֵ�Ѿ�������䣬�Ǿ�
��ĺ����������Ǵ����乵�ﴫ����.�����ϵ�֮����С·���ٷ�ʯ
���Ѷ��£�Լ����ɣ�����ף�һƬ����׳�۵��ٲ�������������
��ǰ��
LONG
	);
	set("cost", 2);
	set("outdoors", "dali");
	set("exits", ([
		"southdown" : __DIR__"qingtan.c",
		"northwest" : __DIR__"chhill5.c",
		"eastdown" : __DIR__"road7.c",
		]));
	set("no_clean_up", 0);
        set("fjing", 1);

	setup();
}
