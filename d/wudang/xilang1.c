// Code of ShenZhou
// xilang1.c �������� 
// xQin 11/00

inherit ROOM;
void close_men();
string look_men();

void create()
{
	set("short", "��������" );
	set("long", @LONG
������һ���ľ��������ϡ������Ǻ�������һ�����ڵ��ţ�men����
��������䵱Ů���ӵ���Ϣ�ҡ��߹��������Լ�ŵ�һ���ɱ��ߵ�ҩ��Ʈ��
��ҩ�㡣
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"danyaofang",
		"east" : __DIR__"hd_zoulang",
		"west" : __DIR__"xilang2",
	]));
	
	set("item_desc",([
        "men"        :    (: look_men :),
        ]));
        
        set("objects", ([
        "kungfu/class/wudang/qingfeng": 1,
        "kungfu/class/wudang/mingyue": 2,
        ]));
    
	set("cost", 1);
        setup();
}


void init()
{
    add_action("do_knock", "knock");
    add_action("do_push", "push");
}

int close_men()
{
    object room;

    if(!( room = find_object(__DIR__"xiuxishi2")) )
        room = load_object(__DIR__"xiuxishi2");
    if(objectp(room))
    {
        delete("exits/south");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", this_object());
        room->delete("exits/north");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/south"))
        return notify_fail("�����Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!( room = find_object(__DIR__"xiuxishi2")) )
        room = load_object(__DIR__"xiuxishi2");
        
    if(objectp(room))
    {
    if ((int)room->query_temp("sleeping_person") > 0)
    {
        message_vision(
        "$N�����������һ���ţ����������洫��һ���������������\n"
	"��Ȼ�������˯�ø������Ƶģ���ô�ö�û����\n",
        this_player());
    } else if ((int)room->query_temp("person_inside") > 0)
    {
    	switch( random(2) )
    	{
    	case 0:
        	message_vision(
        	"$N������������ţ�ֻ�����������˺ܲ��ͷ��غ𵽣�\n"
		"�����¾������ţ���˯���ˣ�������������\n",
        	this_player());
        	
        	break;
       	case 1: 
        	message_vision(
        	"$N������������ţ�ֻ����������Щ�춯��\n"
		"����������������ȥ���ò��������Ƿ��š�\n",
        	this_player());
        	
        	break;
	}       	
	        	
    } else
    {
	room->delete_temp("sleeping_person");
        message_vision("$N������������ţ��ˡ��ˡ��ˣ������ˡ��ˡ��ˣ�����\n",
            this_player());
    }
    }

    if(objectp(room))
    	message("vision",
    	"���洫��һ��������������ŷ�����һ�ƣ���"+this_player()->query("name")+"һ��������վ�����⣬\n"
    	"������Ҳ�������Ϣ��\n", room);
        
    return 1;
}

int do_push(string arg)
{
    object room;

    if (query("exits/south"))
        return notify_fail("���Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!(room = find_object(__DIR__"xiuxishi2")))
        room = load_object(__DIR__"xiuxishi2");
        
    if(objectp(room))
    {
    if((int)room->query_temp("person_inside")<=0)
    {
	 	room->delete_temp("person_inside");
        set("exits/south", __DIR__"xiuxishi2");
        message_vision("$N����ذ����ƿ���\n", this_player());
        room->set("exits/north", __FILE__);
        remove_call_out("close_men");
        call_out("close_men", 10);
    } else 
    {
        message_vision("$N������ƿ���ȴ�����ű��˴����������ˡ�\n",
	 	this_player());
    }
    }

    return 1;
}


string look_men()
{
    object room;

    if (query("exits/south"))
	return ("���Ϲ��˸����ӣ��Ͽ��δ�\n");

    if(!( room = find_object(__DIR__"xiuxishi2")) )
        room = load_object(__DIR__"xiuxishi2");

    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
	return ("���Ϲ��˸����ӣ��������\n");
    } 
    
    return ("���Ϲ��˸����ӣ�Ů������Ϣ��\n");
}

int valid_leave(object me, string dir)
{
	object room;
        if (me->query("gender") != "Ů��" && dir == "south" )
           return notify_fail("������Ů������Ϣ�ң����ȥ���װɣ�\n");
           
        if(!( room = find_object(__DIR__"xiuxishi2")) )
        	room = load_object(__DIR__"xiuxishi2");
        
        if(objectp(room) && dir == "south")
	{
		room->add_temp("person_inside", 1);
		// will open the door if ppl inside stay too long 
		remove_call_out("force_open");
		call_out("force_open", 299, room);
	}		
                
        return ::valid_leave(me, dir);
}
int force_open(object room)
{
	if ( !objectp(room) ) return 0;
    if((int)room->query_temp("person_inside")<=0) return 0;
    
    room->delete_temp("person_inside");
    set("exits/south", __DIR__"xiuxishi2");
    room->set("exits/north", __FILE__);
    message("vision", "����ͻȻ������صĽŲ�������Զ����������ǰͣ������������\n"
    	"����Ϫž�ذ��Ŵ򿪣����ͷ������һ�����ɣ���������˻�����ȥ����ʲô��\n", room);
    remove_call_out("close_men");
    call_out("close_men", 10);
}
