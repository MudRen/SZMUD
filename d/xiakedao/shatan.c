//Cracked by Roath
// Copy from  /d/shaolin/hanshui1.c
// Date: Long /8/1/97
// modified by  aln  5 / 98

inherit __DIR__"no_pk_room";

void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();

void create()
{
    set("short", "ɳ̲");
    set("long", @LONG
�����Ĵ�һ���ޱߡ����߲�Զ��ͣ�ż�ֻС����ϸϸ�İ�ɳ��
���ڽ�������ĺò��������ʱ�м�ֻСз���ж�����һ��ǳǳ����
��ָ�򱱱ߡ�һ������������������΢Ц��
LONG
    );

    set("exits", ([
		   "east" : __DIR__"shatans2",
		   "north" : __DIR__"xiaolu",
		   "northwest": __DIR__"haibian3",
    ]));
    set("objects", ([ 
		     __DIR__ +"npc/yufu" : 1, 
    ]));
    set("no_fight", "1");
    set("outdoors", "xiakedao");
    setup();
}

void init()
{
        object me = this_player();

        ::init();

        me->set("xkd/set", 1);
//        if ((int)me->query_temp("marks/��") > 0)
//		  {       call_out("check_trigger", 1);
//        }
		call_out("check_trigger", 1);
}

void check_trigger()
{
	 object room;

	 if(!query("exits/enter") ) {
		  if( !(room = find_object(__DIR__"chuan")) )
				room = load_object(__DIR__"chuan");
		  if( room = find_object(__DIR__"chuan") ) {
				if((int)room->query("yell_trigger")==0 ) {
					 room->set("yell_trigger", 1);
					 set("exits/enter", __DIR__"chuan");
					 room->set("exits/out", __FILE__);
					 message("vision", "�����������һ��С��ʻ�˹���\n", this_object());
					 message("vision", "�������ؿ����˰��ߡ�\n", room);
					 remove_call_out("on_board");
					 call_out("on_board", 15);
				}
				else
					 message("vision", "���Ǹ��˵�������������ˣ������������ɡ�\n",this_object() );
		  }
		  else
				message("vision", "ERROR: boat not found\n", this_object() );
	 }
	 else
		  message("vision", "���˵���������������أ���ȥ�ɡ�\n", this_object() );
}

void on_board()
{
	 object room;

	 if( !query("exits/enter") ) return;

	 message("vision", "������������ʻȥ��\n",
		  this_object() );

	 if( room = find_object(__DIR__"chuan") )
	 {
		  room->delete("exits/out");
		  message("vision", "����΢΢һ�����밶����ʻȥ��\n", room );
	 }
	 delete("exits/enter");

	 remove_call_out("arrive");
	 call_out("arrive", 20);
}

void arrive()
{
	 object room;
	 if( room = find_object(__DIR__"chuan") )
	 {
		  room->set("exits/out", __DIR__"shatan3");
		  message("vision", "����΢΢һ�𣬴������ˡ�\n",room );
	 }
	 remove_call_out("close_passage");
	 call_out("close_passage", 20);
}

void close_passage()
{
	 object room;
    if( room = find_object(__DIR__"chuan") ) {
        room->delete("exits/out");
        message("vision","���������밶��ʻ���ϡ�\n", room);
        room->delete("yell_trigger"); 
    }
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"chuan") )
        room->delete("yell_trigger"); 
}
int valid_leave(object me, string dir)
{
	object *iv;
	int i;

//        if ( (! me->query_temp("marks/��") ) && (dir =="enter"))
//					 return notify_fail("������һ��˵����û�е���ͬ�⣬�㲻���뵺��\n");

	iv = all_inventory(me);

		  if ( dir == "enter") {
					 for (i=0; i<sizeof(iv); i++) {
								if (iv[i]->is_character())
		return notify_fail("�㲻�ܴ�����������뿪���͵���\n");
					 }
	}
		  return ::valid_leave(me, dir);
}


