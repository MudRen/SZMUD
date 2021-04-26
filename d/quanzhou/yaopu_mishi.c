// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ���ؽѣ�������ҩ���ղ����ҩ��ĵط�������һ�����
�ӣ�shelf��������ҩ�ĺ�����С��ƿ��������һֻ��ҩ¯�������о���ҩ
ζ��������һ������(chair)��
LONG
	);
	set("no_clean_up", 0);

        set("item_desc", ([
        "chair" : "һ�����ӣ�Ĩ�õúܸɾ����α�����˫�������ͼ����
�������̵�����������������צ������һ�������α�����ⷢ��������(Iron
Ball)��\n",
	"shelf" :
"һ������ӣ��ѷ��˲��ٶ���������(search)û׼���кö�����\n",
	]));

    set("objects", ([
         __DIR__"obj/yaolu" : 1,
]));
	setup();
}


void init()
{
	add_action("do_turn","zhuan");
	add_action("do_turn","turn");
	add_action("do_search","search");
}

int do_turn(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg == "" ) return 0;
	if( arg == "ball" || arg == "qiu")
	{
        message_vision("$N��������һ�����ӣ��������α�������һ������\n\n"+
        "���Ҷ���һ����ӻ�����һ����ȥ��¶��һ���󶴡�\n",me);
        set("exits/up", __DIR__"neitang");
        remove_call_out("close_door");
        call_out("close_door",15,me);

		return 1;
	}
	else
		return notify_fail("��Ҫ��ʲô��\n");
}

void close_door(object me)
{
	tell_room(this_object(),"���Ҷ����İ����ֻ������˻�����\n");
	delete("exits/up");
}

int do_search(string arg)
{
	object ob,me;
	me = this_player();
	if (!arg || arg == "") return 0;
	
	if (arg == "jia" || arg == "shelf")
	{
		if (query("searched"))
			return notify_fail("���ڼ����Ϸ�Ѱ��һ�󣬵�ʲô��û�ҵ���\n");

                switch (random(7))
		{
			case 0:
			ob = new(DRUG_D("yangxin"));
			break;
			case 1:
			ob = new(DRUG_D("jinchuang"));
			break;
			case 2:
			ob = new(DRUG_D("baicao-dan"));
			break;
			case 3:
			ob = new(DRUG_D("yulu-wan"));
			break;
			case 4:
			ob = new(DRUG_D("xxqingxin-san"));
			break;
			case 5:
			ob = new(DRUG_D("heishi-dan"));
			break;
                       case 6:
                        ob = new(DRUG_D("dali-wan"));
                       break;
		}

		set("searched",1);		
                  message_vision("$N��һ��Сƿ�����ҵ�һ��"+ob->query("name")+"��\n",me);
		ob->move(me);
		return 1;
	}
}	

