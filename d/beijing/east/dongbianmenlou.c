//Cracked by Roath
// Room: /d/beijing/east/dongbianmenlou.c

inherit ROOM;

void create()
{
	set("short", "�����ų�¥");
	set("long", @LONG
���Ƕ����ų����ϵ���¥��һ�Ӷ�׳�����سǾ���������
�����ֳִ󵶳�ì��ǿ�������������ע���ų��¹������ˣ�
���������ǳ����ı������ǽ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"chengqiang6",
	"west" : __DIR__"chengqiang4",
	"down" : __DIR__"dongbianmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
