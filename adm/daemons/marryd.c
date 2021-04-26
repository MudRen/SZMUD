// Code of ShenZhou
// marryd.c
//
// Zhuang@XKX 081496

#include <ansi.h>
#include <dbase.h>

private int bad_news(object, int);

void create() { seteuid( getuid() ); }

// setup marriage, does not check for validity
int setup_marriage(object p1, object p2, object r1, object r2)
{
	string title1, title2, id1, id2;
	
	if( p1->query("gender") == "Ů��" ) {
		title1 = "�ɷ�";
		title2 = "����";
	} else {
		title1 = "����";
		title2 = "�ɷ�";
	}
	
        id1 = p1->query("id");
        id2 = p2->query("id");
	p1->set("spouse/id", id2);
	p1->set("spouse/name", p2->query("name"));
	p1->set("spouse/title", title1);
	p2->set("spouse/id", id1);
	p2->set("spouse/name", p1->query("name"));
	p2->set("spouse/title", title2);
	if (p1->query("last_spouse_id") != id2)
	    p1->add("married_times", 1);
	p1->set("last_spouse_id", id2);
	if (p2->query("last_spouse_id") != id1)
	    p2->add("married_times", 1);
	p2->set("last_spouse_id", id1);
	p1->save();
	p2->save();
	r1->move(p2);
	r2->move(p1);
	
	return 1;
}

// break marriage
int break_marriage(object breaker)
{
	object victim, ring;
	mapping spouse;
	
	if( !mapp(spouse = breaker->query("spouse")) )
		return 0;
		
	breaker->delete("spouse");
	if( objectp(ring = breaker->query_temp("ring_worn")) )
		ring->init();
		
	if( objectp(victim = find_player(spouse["id"])) )
		bad_news(victim, 1);
	
	return 1;		 	
}

// validate marriage immediately after relogin
int validate_marriage(object me)
{
	object ob, body;
	string id;
	
	if( !stringp(id = me->query("spouse/id")) ) return 0;
	
	// spouse is online
	if( objectp(body = find_player(id)) && geteuid(body) == id ) {
		if( me->is_spouse_of(body) )
			return 1;
		else
			return(bad_news(me, 0));
	}
	
	// spouse is offline, this is tricky
	ob = new(USER_OB);
        ob->set("id", id);
	        
	if( !ob->restore() ) {
		destruct(ob);
		return(bad_news(me, 0));
	}
	
	if( !me->is_spouse_of(ob) ) {
		destruct(ob);
		return(bad_news(me, 1));
	}	
	
	destruct(ob);
	return 1;	
}

private int bad_news(object sb,int x)
{
	object ring;
	if(x) tell_object(sb, HIB "\n"+sb->query("spouse/name")+"�Ѿ�����������飬.....\n\n" NOR);		
	else tell_object(sb, HIB "\n������ͻȻ�ӹ�һ˿����ĸо�......\n\n" NOR);
	sb->delete("spouse");
	if( objectp(ring = sb->query_temp("ring_worn")) ) {
		ring->init();
		sb->delete_temp("ring_worn");
	}
		
	return 0;
}
