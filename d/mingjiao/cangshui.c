// Code of ShenZhou
// Room: /d/mingjiao/cangshui.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
�˴������̺�ˮ�촢�ض�ˮ֮�ء����ں������ˡ������������ٸ�
װ����ˮ�Ĵ���Ͱ���˶�ˮ�Ǳ�һ�㣬���������º��ı�ˮ��̶̶ˮ����
���ɣ��涾�ޱȡ���������һ��ճ�ϣ�Ƭ��֮�䣬Ƥ�����ã�����Ѫˮ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang",
	]));
	set("objects",([
		__DIR__"obj/gang" : 1,
	]));

	set("no_clean_up", 1);
	set("cost", 1);

	setup();
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}