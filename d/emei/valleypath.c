// Code of ShenZhou
// d/emei/valley.c ɽ��С��
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "ɽ��С��");
	set("long", @LONG
����ɽ���е�С����ͨ���ľ����֮�����������Ÿ��ֻ�����ľ������ݣ�
ľ�ȣ�ľ������ɯ须���ޥ����ľܽ�ء�����ɢ�������ĵ�������
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
	    	"�����"	:
"����ݵ�Ҷ�ӳʳ�����԰�Σ����ŵ��Ϻ�ɫ��С����\n",
		"ľ����"	:
"ľ����֦��ïε�������·�ܽ�ػ�����\n",
		"ɯ须�"	:
"ɯ须��������ף����ɰ��棬������֮�����������Ժ�֮�߹�Ʒ�¡�\n",
        ]));
        set("exits", ([
                "northeast" : __DIR__"grassland",
                "west" : __DIR__"valley",
        ]));

	set("cost", 2);
	set("flower_count", 10);
	setup();
}

void init()
{
	add_action("do_pick", "pick");
	add_action("do_pick", "zhai");
}

int do_pick(string arg)
{
	object me = this_player();
	object flower = new(__DIR__"obj/flower");

	if ( !arg || arg == "") return 0;

	if ( arg == "flower" ){
		if (query("flower_count") < 1) {
			tell_object(me, "��ժ�Ļ��Ѿ�ժ���ˡ�\n", me);
			return 1;
		}
		else {
                	message_vision("$Nժ��һ��Ұ����\n", me);
			flower->move(me);
			add("flower_count", -1);
	        	return 1;
		}
	}
	return 0;
}

