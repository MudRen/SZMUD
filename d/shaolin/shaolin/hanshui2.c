// Room: /d/shaolin/hanshui2.c
// Date: YZC 96/01/19
// modified by aln 4 / 98

inherit FERRY;

void create()
{
	set("short", "��ˮ����");
	set("long", @LONG
��ˮ����Ҳ���൱���֣��Ա����ɿ�������һ����ֱ�Ĺٵ�
ֱͨ�������˵���紾�ӣ�·�Լ��������������������Ҷ���һ
����ġ��ơ���ӭ��Ʈ�εΪ׳�ۡ�Ҳ�в���С����·����
����ѱ棬ȴҲ����ʢ����ȴ��
LONG);
	
	set("exits", ([
		"north" : __DIR__"nanyang",
                "west" : __DIR__"riverbank",
		]));

	set("item_desc", ([
		"river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
		]));

        set("outdoors", "shaolin");
        set("resource/water", 1);
	set("cost", 1);

	set("name", "��");
	set("boat", __DIR__"duchuan");
	set("opposite", __DIR__"hanshui1");
      set("fjing",1);
	setup();
}

