// Code of ShenZhou
//Kane

inherit FERRY;

void create()
{
	set("short", "̫��");
	set("long", @LONG
̫���ų������������ݣ�������������֮ˮ�Թ��ڴˡ�
��ʱ���������޲������۽Ա̣���ʮ����Դ�ͦ����������ǧ�겨
��֮�У����������Ļ��󳩡��ɴ˵Ǵ���ǰ��̫��֮�еĹ���ׯ��
LONG
	);
	set("exits", ([
	 	"east" : __DIR__"taihu2",
		"southwest" : __DIR__"road",
	]));
	set("cost", 2);
	set("outdoors", "guiyun");

	set("objects", ([
		"/d/taihu/npc/guanying" : 1,
	]));

	set("name", "��");
	set("boat", __DIR__"duchuan");
	set("opposite", __DIR__"matou");

	setup();
}
