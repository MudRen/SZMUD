// Code of ShenZhou
// Room: /d/xixia/daoguan.c

inherit ROOM;

void create()
{
	set("short", "���ɵ���");
	set("long", @LONG
�����ǰ��ɵ��ۣ����а��ɵ�����Ź��ϡ�������������Ȱ��ɵ�����
�㰸���������ơ���ǽ���ż���̫ʦ�Σ����Ϸ��ż������š��������������ȣ�
�����Ƕ���� �ϱ��Ǻ�Ժ,����Щ�������ϻ������ǵ�ʿ����Ϣ�ĵط�����Ժ
����һ�ھ�����������ȥ�е�������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaolu2",
]));
	set("objects", ([
		__DIR__"npc/laodao" : 1,
	]));
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

	setup();
	replace_program(ROOM);
}
