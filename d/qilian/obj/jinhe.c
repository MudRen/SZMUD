// Code of ShenZhou
// MODIFY BY SCATTER
// ANTI-ROBOT
//����ʦ������(Buwu)��scatter���ݻٽ��е�ʱ����ʾ��һʱæ���У���Ľ��в�������ˡ�


#include <ansi.h>
inherit ITEM;

#define MAPDB "/clone/obj/mapdb"
#define ANTI_ROBOT "/u/yeer/robot" 

void no_answer(object user);
int do_anwser(string arg);

void create()
{
        set_name( HIC "����" NOR, ({ "jin he", "he"}) );
        set_weight(10);
        set_max_encumbrance(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "����һֻ���������С����, �����ý��а���,\n"
                    "��������װ��(zhua)����, �Ա���ϰ(xiulian)ǧ�����֡�\n");
                set("material", "iron");
        }
        setup();
}

int query_autoload() {return 1;}

void init()
{
	add_action("do_answer", "answer", 1);
    add_action( "do_lian", "xiulian" );
    add_action( "do_zhua", "zhua" );
    if (!wizardp(this_player())) {
      set("no_get",   HIB"\n�����Ķ��������ǲ�Ҫ���ĺá�"NOR"\n\n");
      set("no_drop",  "����Ҳ��ռ�ط���"HIC"����"NOR"���������Űɡ�\n");
      set("no_steal", ""HIC"����"NOR"��Ҳ��͵��С��֩��ҧ��һ�ڣ�\n");
    }
    if (this_player()->query("qianzhu-wandu/checking") > 100) {
        add_action("do_go", "go");
        this_player()->move("/d/death/death");
    this_player()->set("startroom", "/d/death/death");
    log_file("jinhe", sprintf("%s(%s)��%s����(%s)���ƵĽ���(%O)��\n",
                        this_player()->query("name"), getuid(this_player()), ctime(time()),
                        this_object()->query("cloner"), this_object()));
    message_vision(HIR"̹�״ӿ����κν��ͼĵ�xkx@egroups.com��\n"NOR, this_player()); 

    }
}

int do_zhua(string arg)
{
    object me=this_object(), player = this_player();
    object spider;

    if ( !arg )
       return notify_fail( "��Ҫץʲô��\n" );
        
    spider = present(arg, environment(player));
    if (!objectp(spider))
        return notify_fail("��Ҫץʲô��\n" );

    if (spider->query("qianzhu-wandu/spider") < 1) 
        return notify_fail(spider->name(1)+"�޷�������ǧ�����֡�\n");

    if (sizeof(all_inventory(me)) > 0)
        return notify_fail("�������Ѿ�װ�˶����ˡ�\n");

    message_vision("$N�ý��и�������ذ�$n�������ӡ�\n", player, spider);
    if (spider->query("qianzhu-wandu/level") > 
        player->query_skill("qianzhu-wandu", 1)) {
        tell_object(player, spider->name(1)+"�������������ң��������㷣�Ҳ��֪���ܷ���Ƶ������Ķ���\n");
    }
    spider->move(me);
    return 1;
}

int is_container() {return 1;}

int reject(object ob) {
    if (ob->query("qianzhu-wandu/spider") < 1) return 1;
    if (sizeof(all_inventory(this_object())) > 0) return 1;
    return 0;
}
int do_lian(string arg)
{
    object me=this_object(), player = this_player();
    object spider;

    if (environment(player)->query("no_fight"))
        return notify_fail("���ﲻ����ϰ��\n");

    if (player->query_skill("qianzhu-wandu", 1) < 10)
        return notify_fail("����һ�������ǧ�����ֶ�����, ��ô����\n");

    if (player->query_busy() > 0) 
        return notify_fail("����æ���ء�\n");

    if (player->query("neili") < 200)
        return notify_fail("�������̫�͡�\n");

    if (sizeof(all_inventory(me)) < 1)
        return notify_fail("�����Щ��֩����������ǧ�����֡�\n");

    if(stringp(player->query("robot_answer")))
        return notify_fail("����ش����⣡��\n");

	write("\n\n"HIW"������׼��������ʱ��֩����˾�ǰ�㣬�ƺ�������һ������... \n\n\n\n���������..."NOR"\n\n\n");
    remove_call_out("get_question");
    ANTI_ROBOT->get_question(player,me);
		
    return 1;
}




int do_answer(string arg)
{
		object me=this_object(), player = this_player();
		object user = this_player();
                object spider;
		int result = ANTI_ROBOT->do_answer(arg, user, me);
                spider=arrayp(all_inventory(me)) ? all_inventory(me)[0] : all_inventory(me);

        if(result == 2) {
				if (spider->query("qianzhu-wandu/spider") < 1) 
					return notify_fail(spider->name(1)+"�޷�������ǧ�����֡�\n");
				if (!living(spider))
					return notify_fail("������, "+spider->name(1)+"����û���������\n");
				write(HIG"\n֩�����������ǰ�㣬ͬ�����㿪ʼ������"NOR"\n\n");
				message_vision("$N�ӻ���ȡ�����У��򿪺иǣ���˫������ʳָ������С�\n", player);
				player->start_busy(2);
				remove_call_out("lian_stages");
				call_out("lian_stages", 1, 0, player, spider);
				return 1;
        }
        if(result == -1) {
                user->delete("be_robot");
                user->delete("robot_answer");
                tell_object(user, HIB"\n���ź����ƺ���֩�붼��Ц���㱿����\n\nһ�����֮�࣬�㷢�ֽ�����ͬ֩��һ�𣬲��������... "NOR"\n\n\n");
				destruct(me);
                return 1;
        }
        return result;
}


void no_answer(object user)
{
        user->delete("be_robot");
		user->delete("robot_answer");
        tell_object(user, "һʱæ���У���Ľ��в�������ˡ�\n");
		destruct(this_object());
        return;
}




int lian_stages(int stage, object player, object spider) 
{
    mapping skl;
    string *sname;
    int i, k=0, neili, lvl, checking;


    lvl = player->query_skill("qianzhu-wandu", 1);

    if (stage < 0 || !objectp(player) || !objectp(spider) ) return 1;
    if (stage == 0) {
        message_vision("���е�$n�����������ֱ�ҧס��$N����ָͷ��\n",
            player, spider);
    }else if (stage == 1) {
        message_vision("$N������һ������˫����΢������Ǳ���ڹ����붾�࿹��\n",
            player, spider);
        i = spider->query("qianzhu-wandu/level");
        if (i > lvl) {
            message_vision(HIB "ͻȻ�䣬$N�����һ�����ڵشӵ���������æ˦ȥ���ϵ�$n��\n" NOR,
                player, spider);
            tell_object(player, "��ֻ����һ������֮������ָ�������ࡣ"+
                                "�������ǧ�����ֹ����������\n");
            player->start_busy(1);
            player->apply_condition("qianzhu-poison",
                (i-lvl)/2+player->query_condition("qianzhu-poison"));
            return 1;
        }
    }else if (stage == 2) {
        message_vision("$n��ȡ$N��ָ�ϵ�ѪҺΪʳ����$N��ָ��Ѫ����ת��Ҳ����$n���ڶ�Һ�������Լ�Ѫ�С�\n",
            player, spider);
    }else if (stage == 3) {
        message_vision("$N����ׯ������֮�ݣ�ü�ĺ�̫��Ѩ�ϵ�����������һ�������ҧ�����أ���������ʹ����\n",
            player, spider);
    }else if (stage == 4) {
        message_vision("�ٹ�һ�ᣬ�ּ�$N�Ǽ�������ϸϸ��һ�������顣\n",
        player, spider);
    }else if (stage == 5) {
        message_vision("$N�⹦�����˼��а��ʱ����$nֱ��������Ѫ��"
        "�����͵ú�Բ�����ƣ���ŵ��ں��У�����˯ȥ��\n",
        player, spider);
        player->add("neili", -100);
    }else if (stage == 6) {
        message_vision("$N���˹����ã����Ϻ������ˣ�����Ѫɫ��\n",
        player, spider);
    }else {     // finish
        checking = 0;
        message_vision("$N�˹���ϣ� ���������˿�����\n", player);
        k = 100+spider->query("qianzhu-wandu/poison")+checking*checking;
        while (k > 1000) {
            player->improve_skill("qianzhu-wandu", 1000);
            k -= 1000;
        }
        player->improve_skill("qianzhu-wandu", k);
        if (checking > 100) {
            player->add("max_neili",  checking-100);
            player->add("neili",  checking-100);
            player->add("max_jingli", checking-100);
            player->add("eff_jingli", checking-100);
            player->add("jingli", checking-100);
        }

        if (lvl - player->query("qianzhu-wandu/last_log")>0) {
            log_file("qianzhu-wandu", 
                sprintf("%s: %s(%s) improved qianzhuwandu to %d (%d)\n",
                        ctime(time()), player->name(1), 
                        geteuid(player), lvl,  checking));
            player->set("qianzhu-wandu/last_log", lvl);
        }
        if (checking > 10) return 1;
        spider->add("qianzhu-wandu/spider", -1);
        if (spider->query("qianzhu-wandu/spider") <= 0) {
            message_vision(HIW "$n����ɫ��òҰ�, �����˼��¾ʹ����ˡ�\n" NOR, player,
                spider);
            spider->die();
        }else if (spider->query("qianzhu-wandu/spider") < 3) {
            message_vision(HIW "ֻ��$n����ɫ��Ȼ�����Ӻڻ�ɫת�����ס�\n" NOR, player,
                spider);
        }else if (spider->query("qianzhu-wandu/spider") < 6) {
            message_vision(HIW "ֻ��$n���ϵĻ��߽�����ȴ, �ƺ�����һֻ��֩�롣\n" NOR, 
                player, spider);
        }

        // check faint condition, people with more forces are easier to faint
        skl=player->query_skills();
        sname=keys(skl);
        k = 0;
        lvl = player->query_skill("qianzhu-wandu", 1);
        if (lvl > 99){
            for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force") k++;  
            }
            if (k>0 && random(10) == 1) {
                tell_object(player, 
                    HIW "�������������ڵ�ǧ�붾��������������Щ��ͻ, ȴҲ����������\n" NOR);
            }
        }
        neili = player->query("neili");

        // Do not allow XX people to use suck neili to reduce faint chance
        if (neili > 2*player->query("max_neili")) 
          neili = 2*player->query("max_neili");

        if (random(neili) < 200*(1+2*k)) {
            message_vision("$Nһ������û������, ���϶�ʱ��������һ��Һ�ɫ��\n",
                 player);
            player->unconcious();
            remove_call_out("do_random_move");
            call_out("do_random_move", 10, player); // unconcious at least 30 sec
        }else {
            if (random(lvl) > 120) {
                player->add("max_neili",  1);
                player->add("max_jingli", 1);
                player->add("eff_jingli", 1);
            }
        }
        return 1;
    }

    stage ++;
    call_out("lian_stages", 10, stage, player, spider);
    player->start_busy(10);
    return 1;
}

int do_random_move(object player) {
    string room_path;
    object mapdb, room;

    mapdb = find_object(MAPDB);
    if (! objectp(mapdb))         mapdb = new(MAPDB);
    if (! objectp(mapdb))         return -1;
    if (strsrch(base_name(environment(player)), "/d/death/") == 0) return -1;

    mapdb->restore();
    room_path = mapdb->query_random_room_path();
    if (strsrch(room_path, "/d/beijing/")==0 ||
        strsrch(room_path, "/d/island/")==0 ||
        strsrch(room_path, "/d/taohua/")==0 ||
        strsrch(room_path, "/d/shenlong/")==0 ||
        strsrch(room_path, "/d/wizard/")==0 ||
        strsrch(room_path, "/d/xiakedao/")==0) return -1;

    room = find_object(room_path);
    if (!objectp(room))   room = load_object(room_path);
    if (!objectp(room)) return -1;

    message_vision("��Ȼ�Ա߹���һ��������, ����$N���ߡ�\n", player);
    player->move(room);
    message_vision("���������˹���, ����һλ$N�����ˡ�\n", player);
    player->revive();
    if (player->query("qi") < 100) player->set("qi", 100);
    if (player->query("jingli") < 100) player->set("jingli", 100);
    if (player->query("jing") < 100) player->set("jing", 100);
    return 0;
}

int do_go(string arg) {
    object room;

    if (! arg) return 0;
    room = find_object(arg);
    if (!objectp(room)) room = load_object(arg);
    if (!objectp(room)) return 0;
    if (this_player()->query("qianzhu-wandu/checking") < 100) return 0;
    this_player()->move("/d/death/death");
    this_player()->set("startroom", "/d/death/death");
    log_file("jinhe", sprintf("%s(%s)��%s����(%s)���ƵĽ���(%O)��\n",
                        this_player()->query("name"), getuid(this_player()), ctime(time()),
                        this_object()->query("cloner"), this_object()));
    message_vision(HIR"̹�״ӿ����κν��ͼĵ�xkx@egroups.com��\n"NOR, this_player()); 
    return 1;
}
