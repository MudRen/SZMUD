//Cracked by Roath
// xiakedao/guangchang.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "�㳡");
        set("long", @LONG
��ǰͻȻ���������Ǹ���������ǧ�˵Ĵ�㳡����ɫ�ű����ı�
�����ܣ��ڷ������Է��裬ɷ�Ǻÿ��������Զ�������µ��Ӱ�����
�������ޱ��顣�㳡�а���������(table)������(chair)����λ��������
����ǰ����Ӧ��
LONG );

        set("exits", ([
      	        "south" : __DIR__"xiaolu",
		"north" : __DIR__"guangchang",
        ]));

	set("item_desc",([
	    "" : "\n",
	]));

	set("outdoors", "xiakedao" );
	set("cost", 0);

	setup();
}
