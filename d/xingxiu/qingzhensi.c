// Code of ShenZhou
// qingzhensi.c ������������
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "������������");
	set("long", @LONG
�������������ǻؽ����������£���Ժ���š�ͥ԰�����ú���
�ݵ��Ĵ󲿷���ɣ�������ΰ�������ûʡ�ǳ��ɫ�Ĵ����Ϸ����п���
�����ģ���Χ������ά����ľ���ͼ����ÿ����գ������ǹŶ����
�����νڵ��峿ʱ�֣�����һ�����ʱ��ȫ��������ص���˹�ַ�ӵ��
���ڣ�������ǰ�Ĺ㳡Ҳվ���˽�ͽ������֮�����˳Ծ���
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"shule",
	]));
	set("objects", ([ 
	    "/d/xingxiu/npc/moslem" : 1,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
