// Code of ShenZhou
// long_shiliang.c ��ʯ��
// xQin 11/00

inherit ROOM;
#include <ansi.h>
string look_lu();
int burnt, start_burn; 
int is_burning();

void create()
{
        set("short", "��ʯ��");
        set("long","ʯ���ϵ����վ��������Ṧ�������޷�Ծ������ֻ��ʯ�����˵����һ\n"
"����¯(lu)��\n\n"
"    "HBWHT+HIC"�����Ͻ����죬������ȣ����������������ƻþ���\n\n"NOR
	);
	set("item_desc",([
            "lu" : ( :look_lu:),
        ]));
        setup();

        burnt = 0;
	call_out("burn", 120, 1);

}

void init()
{
	add_action("do_jing", "jing");
	add_action("do_jump", "jump");
}

int is_buring()
{
	return (burnt < 3);
}	

void burn(int phase)
{
	burnt = phase;
	
	if (burnt < 3) call_out("burn", 120, phase + 1);

} 
string look_lu()
{

	switch (burnt) {
	case 0:
		return(YEL"��¯�Ϲ��������ϵ���𣬷ҷ����ܡ�\n"NOR);
		break;
	
	case 1:
		return(YEL"��¯���������ƣ�����յ�������\n"NOR);
		break;
		
	case 2:
		return(YEL"��¯�ϵ�����Ѿ����˴�룬�������̣�������Ϣ��\n"NOR);
		break;
		
	default:
		return(YEL"��¯��ֻʣ��һ���̻ң��������˾�(jing)��ͷ�㣡��\n"NOR);
		break;
		
		}
}
int do_jing(string arg)
{
	object obj, me;
	
	if ( !objectp(me = this_player()) ) return 0;	
	
	if (!arg ) return notify_fail("��Ҫ��ʲô��\n");  
					
	if( !objectp(obj = present(arg, me)) )
		return notify_fail("������û������������\n");
	           
	if ( obj->query("id") != "incense" 
	 ||  obj->is_character() ) return notify_fail("ֻ�ܾ��㣡\n");  
	
	burnt = 0;
	remove_call_out("burn");
	call_out("burn", 120, 1);
	
	message_vision(HIC"$N�ó�һ"+obj->query("unit")+obj->query("name")
		+"�����������ز�����ͷ����¯�ϡ�\n"NOR, me);
	if (me->query("family/family_name") == "�䵱��" )
	me->add("combat_exp", 20+random(20));
	me->add("potential", 10+random(10));	
	if (me->query("age") < 20 && me->query("wudang/offerring") < 60)
	me->add("wudang/offerring", 2);
	if (me->query("age") < 30 && me->query("wudang/offerring") < 120)
        me->add("wudang/offerring", 2);
	if (me->query("age") > 30 && me->query("wudang/offerring") < 150)
	me->add("wudang/offerring", 2);	                                         		                              		

	destruct(obj);
	
	return 1;		
}

int do_jump(string arg)
{
	object me;
	int lv, cost;
	me = this_player();
	
	
	if(me->is_busy())
        return notify_fail("�㻹��æ���ء�\n");
        
        cost = (me->query_dex()*me->query_skill("dodge")/ me->query_con() )/10;
        if (cost < 10) cost= 10;
        if( me->query("jingli") < 30)
        return notify_fail("���Ѿ���ƣ�����ˡ�\n");
        
	if (arg == "back" || arg == "shidian" ) {      
	message_vision("$N��������ʯ�\n\n", me);
        me->move(__DIR__"shidian");
        message("vision", me->name() + "�������ʯ��������������\n",environment(me), ({me}) );
        me->add("jingli", -cost);  
        
	lv = me->query("int", 1)*2;
	if (me->query_skill("dodge") > 200) lv /=2;
	if (me->query_skill("dodge") > 300) lv /=3;
	if (me->query_skill("dodge") > 400) lv /=4;
	if (me->query_skill("dodge") > 500) lv /=5;
	
	me->improve_skill("dodge", lv+random(lv) );
	me->start_busy( 1 );
	if (me->query("family/family_name") == "�䵱��" 
	&& me->query_skill("tiyunzong", 1) > 0 )
	me->improve_skill("tiyunzong", random(lv) );
	return 1;
	}
        return 1;
}