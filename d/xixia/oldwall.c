// Code of ShenZhou
// Room: /d/xixia/oldwall.c

inherit FERRY;

void create()
{
	set("short", "�ų���");
	set("long", @LONG
������һ�ιų��ǡ��ഫ�ǵ�����ʼ���������ĸ�������������
ʮ�������ޡ����±�Ǩ���׺�ɣ������������һƬ���棬Ψһ
��ϡ�ɼ����Ǻ����Ƴɵķ��̨���С����һ������������ƺӴ�
������ȥ��������һҶС�۰ڶɳ˿ͣ�����Խ�(yell)һ�´��ҡ�
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"shimen",
  "southwest" : __DIR__"ypshui",
]));

	set("name", "��");
	set("boat", __DIR__"duchuan");
	set("opposite", __DIR__"xhbao");

	setup();
}
