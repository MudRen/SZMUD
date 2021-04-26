// Code of ShenZhou
// Room: /d/xixia/center.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������Ķ������ݵ����Ĺ㳡��Ҳ��������ֵĽ��㴦������
�ǻʳǣ���������ҵ�����ضΣ���������ͨ������������Ӫ��������
�ź����������ǵĸ��ڡ������������������ʼ�ɢ�غ���ҵ���ģ�
Ҳ������ͨ����ԭ�ıؾ�֮�ء���ɫ�˵�������������˻�˺�������
�Ƿ����㳡�յ������յġ�Ҫ���ġ��󸹱��Ĳ���������Я�����
�����ݵ������ǣ�ż��Ҳ����ɫ�ҴҵĽ�����ʿһ�ζ�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nandajie",
  "west" : __DIR__"xidajie",
  "north" : __DIR__"beidajie",
  "east" : __DIR__"dongdajie",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}
