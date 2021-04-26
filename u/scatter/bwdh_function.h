
void init()
{
        object me = this_player();
        if(wizardp(me) || me->query_temp("organizer") ) {
                add_action("do_let", "let");
                add_action( "do_full", "full" );
                add_action("do_kickout", "kickout");
                add_action("do_start", "start");
        }
        add_action("do_get", "get");
        add_action("do_disable", "hit");
		add_action("do_disable", "kill");
        add_action("do_disable", "steal");
        add_action("do_disable", "fight");
        add_action("do_disable", "quit");
        add_action("do_disable", "sleep");
        add_action("do_giveup", "giveup");
        add_action("do_practice",  "practice");
		add_action("do_practice",  "lian");
		add_action("do_study",  "study");
		add_action("do_study",  "du");
}


int do_practice(string arg)
{
                  object me = this_player();
                  tell_object(me, "这里不准练功!\n");
                  return 1;
}

int do_study(string arg)
{
                  object me = this_player();
                  tell_object(me, "这里不准读书!\n");
        return 1;
}

int do_giveup()
{
        object me = this_player();
        message_vision(me->query("family/family_name")+"$N自动认输。\n", me);
        me->quit(me);
        return 1;
}


int do_full( string arg )
{
    object ob, me = this_player();
    if ( !arg ) return notify_fail( "cmd: full id\n" );
    if ( objectp( ob = present( arg, this_object() ) ) ) 
    {
        ob->set( "eff_qi", ob->query( "max_qi" ) );
        ob->set( "qi", ob->query( "max_qi" ) );
        ob->set( "eff_jing", ob->query( "max_jing" ) );
        ob->set( "jing", ob->query( "max_jing" ) );
        ob->set( "neili", ob->query( "max_neili" ) );
        ob->set( "jingli", ob->query( "max_jingli" ) );
        message_vision( "$N一掌拍在$n的头上，$n感到$N的内力滚滚传来，全身立刻充满了活力。\n", me, ob );
    }
    return 1;
}

int do_kickout(string arg)
{
        object ob;
        if(!arg) return 0;
        if(objectp(ob = present(arg, this_object())) ) {
                if(base_name(ob) == "/d/city/npc/fighter") {
                        message_vision("$N将$n踢出擂台。\n", this_player(), ob);
                        ob->quit(ob);
                        return 1;
                }
        }
        return 0;
}

int do_disable(string arg)
{
        tell_object(this_player(), "不能在擂台上这样。\n");
        return 1;
}

int do_start(string arg)
{
        object ob1, ob2;
        if(objectp(ob1 = present("fighter dummy 1", this_object()))
        && objectp(ob2 = present("fighter dummy 2", this_object())) ) {
                message_vision("一声锣响，$N宣布"+ob1->name()+"和"+ob2->name()+"比赛开始。\n", this_player());
                ob1->kill_ob(ob2);
                ob2->kill_ob(ob1);
                return 1;
        }
        return notify_fail("人没到齐！\n");
}

int do_guo(string arg)
{
        object guo = new("/d/quanzhou/obj/renshen-guo");
        guo->move(this_player());
        message_vision("$N变出一人参果。\n", this_player());
        return 1;
}

int do_get(string arg)
{
        object weapon, me=this_player();
        string type;
        if(!arg) return 0;
        if(me->is_busy()) return 0;
        if (sscanf(arg, "%s from jia", type) != 1) return 0;
        switch (type) {
        case "sword":   if(this_player()->query("gender") == "无性")
                                weapon = new("/clone/test/xiuhua");
                        else    weapon = new("/clone/weapon/gangjian");
                        break;
        case "blade":   weapon = new("/clone/weapon/gangdao");
                        break;
        case "stick":   weapon = new("/clone/weapon/gangbang");
                        break;
        case "staff":   weapon = new("/clone/weapon/shezhang");
                        break;
//      case "falun":   weapon = new("/clone/test/falun");
        case "falun":   weapon = new("clone/weapon/falun");
                        break;
        case "whip" :   weapon = new("/clone/weapon/changbian");
                        break;
        case "armor":   weapon = new("/clone/armor/tiejia");
                        break;
        default:        return notify_fail("找不到"+type+"\n");
        }
        if(weapon->move(me)) {
                message_vision("$N从兵器架上取下一"+weapon->query("unit")+weapon->name()+"。\n", me);
                if (me->is_fighting()) me->start_busy(2);
        } else {
                destruct(weapon);
        }
        return 1;
}


int do_let(string arg)
{
        object ob, dummy;
        string pl1, pl2;

        if(!arg) return 0;
        if(sscanf(arg, "%s play %s", pl1, pl2) != 2) {
                pl1 = arg;
                pl2 = arg;
        }

        if(objectp(present("fighter dummy 2", this_object())) ) {
                return notify_fail("已经有两位选手了。\n");
        }
        
        ob = find_player(pl1);
        if(!ob) return notify_fail("没有"+pl1+"这个玩家！\n");
        seteuid(getuid());
        dummy = new("/clone/test/dummy");
        dummy->set("id", pl2);
        if(!dummy->restore()) {
                destruct(dummy);
                return notify_fail("没有"+pl2+"这个玩家！\n");
        }
        dummy->set_temp("link_ob", ob);
        ob->set_temp("body_ob", dummy);
        ob->set_temp("netdead", 1);
        message_vision("$N进入擂台代表$n。\n", ob, dummy);
        message_vision("$N让"+ob->name()+"进入擂台代表"+dummy->name()+"。\n", this_player());
        exec(dummy, ob);
        dummy->set_name(dummy->name(1), ({pl2, "fighter dummy"}));
        dummy->setup();
        dummy->move(this_object());

        return 1;
}

string look_jia()
{
        string msg;
        msg = "这是一个兵器架，十八般武器是应有尽有。\n";
        msg+= "目前存放有剑(sword)，刀(blade)，棒(stick)，杖(staff)，轮(falun)，\n鞭(whip)。还有一些铁甲(armor)。\n";
        msg+= "请用指令“get 种类 from jia”拿取你称手的兵器或甲胄。\n";
        return msg;
}


int valid_leave(object me, string dir)
{
        if(base_name(me) == "/d/city/npc/fighter") return 0;
        return ::valid_leave(me, dir);
}