// Code of ShenZhou
// �ų�
// maco

inherit ROOM;

void create()
{
	set("short", "�ųǽ�Ұ");
	set("long", @LONG
����һƬ�տ���Զ��һ������ɽ�������𣬷�ǰһ���ŵ�
���Ƿ��ݡ�ǧ�������ݶ�ԫʣ�ߣ����Ʋ�������ûһ����������
������ģ�ֺ꣬�����������������һ��ʮ�ַ�ʢ�ĳ��С�һ
����ȥ���߸߰����ķ����α��۴Σ�������Ϣȫ�ޣ�����ȸ���
��֮����˿�����š�
LONG
	);

	set("exits", ([
		"east" : __DIR__"shanlu4",
		"west" : __DIR__"gucheng2",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

