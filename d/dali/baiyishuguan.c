// Code of ShenZhou
// Room: /d/newdali/baiyishuguan.c

inherit ROOM;

void create()
{
	set("short", "�����ֹ�");
	set("long", @LONG
�����������ƾõ���ʷ���������³�ʫ����ʫ�꡻���䶨ʯ�̡���گ������
»Ȱʯ�̡������¡����������İ������ס�������һ������������������д����
ë�ʻ���ǩд��ֽ��ײ��ϡ��������һ����ѧ��Ϊ�˴�д���ţ����ģ���Լ��
�ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dahejie1",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
