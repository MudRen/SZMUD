// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ����ש��ǽ�ĳ��ȣ��ϱߵĹ���ͨ������������������������
������ǰ�����廨������������λ��������治ʱ������Ů�Ľ�Ц����
LONG
	);
	set("exits", ([ 
	    "northwest" : __DIR__"bedroom1",
	    "south" : __DIR__"dating",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
