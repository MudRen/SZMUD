//Cracked by Roath
// xiakedao/liangong.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

int do_tuna(string arg);
int do_dazuo(string arg);

void create()
{
        set("short", "������");
        set("long", @LONG
ɽ������ǽ�ϵ����˻�ѡ����ＫΪ�����������������Ƴ�����
���صĺ�������������������ذ��ż������ţ������������衣����
���������������(dazuo)������(tuna)��
LONG );

        set("exits", ([
      	        "north" : __DIR__"yongdao5",
        ]));
	set("objects", ([ 
		__DIR__ +"npc/shaonian" : 1, 
        ]));

	set("cost", 0);
	setup();
}
void init()
{
        ::init();

	add_action("do_dazuo", "dazuo");
	add_action("do_tuna", "tuna");
}

int do_dazuo(string arg)
{	if (!arg)
	{	write("����(dazuo)������������������ÿ�δ�������Ҫ��ʮ������\n");
		write("�������������������ߵ�������������һ������������\n");
		write("���ͻ��һ�㡣����˱�ƴ����ʱ������������(jiali)��\n");
		write("�ˣ�����ֻ�ܼӵ����ڹ���Ч�ȼ���һ�롣\n");
	}
	return 0;
}
int do_tuna(string arg)
{	if (!arg)
	{	write("����(tuna)����Ϊ������ÿ����������Ҫ��ʮ�㾫��\n");
		write("��������ɰ���ľ�����ߵ������þ�����һ���������þ�\n");
		write("���ͻ��һ�㡣\n");
	}
	return 0;
}
