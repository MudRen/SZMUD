// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "��ͨ��");
	set("long", @LONG
    ��ͨ�£�������ɽ�¡�ɽ��ǰ���²�԰�������̣������˱ǡ���ͨ�裬��
��گʱ��������ֲ�����׿���ɽ������ͦ�㣬��ͨ��һƬ�����ɹŰ���䡣
LONG
	);
	set("cost", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
