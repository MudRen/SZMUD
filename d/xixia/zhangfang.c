// Code of ShenZhou
// Room: /d/xixia/zhangfang.c

inherit ROOM;

void create()
{
	set("short", "�˷�");
	set("long", @LONG
����һƷ���ʷ������赹���е����̣�������̨û����ô�ߡ���ǽ
�����ŷ��ʲ�����ľ��������������������ž���ڴ�����æ�����ˡ���
���м������������ʲ��ں��ţ�����ÿ��Ľ�������Ŀ���١���̨���и�
���Ź��ʵĸ��ݵ���ͷ��������ζ������̫ʦ��������ˮ�̡�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/nuerhai" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dayuan",
]));

	setup();
	replace_program(ROOM);
}
