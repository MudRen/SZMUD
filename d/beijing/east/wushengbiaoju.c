//Cracked by Roath
// Room: /d/beijing/east/wushengbiaoju.c

inherit ROOM;

void create()
{
	set("short", "��ʤ�ھ�");
	set("long", @LONG
�����Ǿ��������ھ�--��ʤ�ھ֣����ھ��ǿ�����������
���������Ǿ��ǵ������ơ����ֺţ�һ������׿������δʧ�ڡ�
��������ͷ�ǡ���ǹ��������ͨ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"chongwendajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
