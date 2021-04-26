// Code of ShenZhou
// houzhu.c ��侸�
// qfy Nov 3, 1996

inherit ROOM;

void check_trigger();
void on_ship();
void arrive();
void close_passage();
int  do_yell(string);

void create()
{
        set("short", "��侸�");
	set("long", @LONG
��侸���Ȫ������ۿ�֮�ס��������ˮ���ƽ�˾�����ĿԶ��������
  һɫ��ε����覡�����ͣ������������ĸ��ִ�ֻ�����ں���ó�׵Ĺ㷺��չ��
Ȫ�������Ϊ������˿��֮·������㡣���ڶ�Ĵ�ֻ�м䣬����һֻ��ս��
(chuan)��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"gangkou4",
	]));

	set("objects", ([ 
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/shuishi" : 1,
        ]));

	set("item_desc", ([
		"chuan" : "����һ�Ҵ�ս�����ոմ�̨�������ˮʦ�ǳ�(cheng)ս�����̡�\n",
        ]));

	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
}

void init()
{
        add_action("do_yell", "cheng");
}

int do_yell(string arg)
{

        object me = this_player();
        object ob;

	if (!arg || arg != "chuan") return 0;

    if(present("shuishi bing", environment(me)))
     {
	if (!(ob = present("shi lingpai",me))) {
		message_vision("ˮʦʿ����$N˵��������Ϊ�������ԼҵĴ���\n",me);
		return 1;
	}	
	message("vision","ˮʦʿ���ӹ����ƣ����ͷ��˵������Ȼʩ�����������ϴ��ɡ�\n", this_object());

	destruct(ob);
	check_trigger();
	return 1;
     }
	else return 0;
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"ship")) )
            room = load_object(__DIR__"ship");
        if( room = find_object(__DIR__"ship") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"ship");
                room->set("exits/out", __FILE__);
                message("vision", "ˮʦʿ����ս���ķ緫����׼���𺽡�\n", this_object());
                message_vision("ˮʦʿ����һ��̤�Ű������ͷ����$N˵���������ɡ�\n", this_player());
                remove_call_out("on_ship");
                call_out("on_ship", 20);
            }
            else
                message("vision", "���ź������տ��ߡ�\n", this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
	
    else
        message("vision", "ˮʦʿ��˵�������������ɡ���\n",
            this_object() );
}

void on_ship()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "ˮʦʿ���Ѵ�ê����˳��ת���緫��\n",
        this_object() );

    if( room = find_object(__DIR__"ship") )
    {
        room->delete("exits/out");
        message("vision", "ս��ʻ����ãã�Ĵ�...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 120);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"ship") )
    {
        room->set("exits/out", "/d/island/diaoyu");
//        message("vision", "ˮʦʿ��˵���������棬Ȫ�ݵ��ˣ���\n",room );
        message("vision", "ˮʦʿ��˵���������棬ǰ�����ֺ�������\n",room );
    }

    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"ship") ) {
        room->delete("exits/out");
        message("vision","ˮʦʿ����̤�Ű���������ս��ʻ����ãã�Ĵ�...\n", room);
        room->delete("yell_trigger");
    }
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"ship") )
        room->delete("yell_trigger");
}

