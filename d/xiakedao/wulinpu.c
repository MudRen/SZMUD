//Cracked by Roath
// /xiakedao/Dong3.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
���͵�������ǲ���ӵ���ԭ���ش�̽���������飬����Ļ�����
����಻Ϊ��֪���������ű�������������(books)�С�ֻ�������
����ȫ�������͵Ƴ��������Ǹ�����ĺõط���
LONG );

	set("exits", ([
		"south" : __DIR__"",
	]));

	set("item_desc",([
	    "books" : 	"�����϶�д��һ���������ɵ����֡�\n",
	]));
	
        setup();
}
void init()
{
        ::init();

	add_action("do_du", "du");
}
int do_du(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail( "����ѧʲ��?\n");
	if ( arg != "book" )
		return notify_fail( "��Ҫ��ʲ��?\n");
	write("�����Ȿ��ĵ�һҳ������д��\n");
	return 1;
}
