//Cracked by Roath
// Room: /d/beijing/west/huichuntang.c

inherit ROOM;

void create()
{
	set("short", "�ش���");
	set("long", @LONG
���Ǿ���һ�����ֺŵ�ҩ�꣬��ֻ���˻��ߵ�ҩ��ǽ�������������
վ��������ȡ��ҩ�ģ�һ���������һ���и���ϸҩ�ģ�����źá���˵��
��ĵ�����ҩ�ǳ����顣һ��С���վ�ڹ�̨���к��Ź˿͡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baozhu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
