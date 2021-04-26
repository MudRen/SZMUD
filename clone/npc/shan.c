// Code of ShenZhou
// /d/changbai/npc/chan.c ����
// ALN 1/98

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define SHANZHENG NPCDATA + "shan-zheng"

#define BANGJIAO  "/d/changbai/bj/"

#define BANGYIN   "/d/huanghe/obj/bangyin"
#define BANGYIN2  BANGJIAO + "bangyin2"
#define JIAN      BANGJIAO + "sword"
#define ZHANGLAO  BANGJIAO + "zhanglao"
#define LAMA      BANGJIAO + "lama"

#define BANGZHU   "/d/huanghe/npc/bangzhu"

inherit NPC;
inherit F_SAVE;

#include <ansi.h>
#include <room.h>
#include <localtime.h>

#include "/d/changbai/bj/info_bang.h"
#include "/d/changbai/bj/info_zhanglao.h"
#include "/d/changbai/bj/info_lama.h"
#include "/d/REGIONS.h"

string ask_bang(string);
string ask_bangyin();
string ask_jianghu();
string ask_jian();
string ask_mizong();

string query_save_file()
{
        return SHANZHENG;
}

void create()
{
        string *bangs;

        seteuid(getuid());

        if (!restore()) {
        set_name("����", ({ "shan zheng", "shan", "judge" }));
        set("nickname", "�����й�");
        set("long", 
"����ƽ�������ֻҪ֪����������ʲô������֮�£���Ȼ����Ҫ�ܡ�\n"
"��������⣬������ͯ�պ׷������֣�����ȴ��ǫ�ͣ����ƽ����ϴ�˵�ĳ������顣\n");
        set("gender", "����");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 900);
        set("max_jing", 500);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 40);
        set("combat_exp", 400000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("wuxingbu", 100);
        set_skill("parry", 100);
        set_skill("cuff", 100);
        set_skill("wuxing-quan", 120);
        set_skill("club", 100);
        set_skill("ding-force", 100);
        set_skill("liuhe-qiang", 120);

        map_skill("club", "liuhe-qiang");
        map_skill("parry", "liuhe-qiang");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("force", "ding-force");

        prepare_skill("cuff", "wuxing-quan");

        bangs = keys(info_bang);
        for(int i = 0; i < sizeof(bangs); i++) {
                set("inquiry/" + bangs[i], (: ask_bang, bangs[i] :));
        }

        setup();
        }
        else {
                //set("id", "shan zheng");
	        set_name("����", ({"shan zheng", "shan", "judge"}));
              //  set_name(query("name"), ({ query("id") }));
                setup();
                clear_condition();  
        }

        set("chat_chance", 10);
        set("chat_msg",({
                (: random_move :)
        }));

        set("inquiry", ([
                "��" : (: ask_bang, "��" :),
                "а��" : (: ask_bang, "а��" :),
                "����" : (: ask_bangyin :),
                "��ӡ" : (: ask_bangyin :),
                "bangzhu" : (: ask_bangyin :),
                "����" : (: ask_jianghu :),
                "jianghu" : (: ask_jianghu :),
                "������" : (: ask_jian :),
                "jian" : (: ask_jian :),
                "����" : (: ask_mizong :),
                "���ڸ���" : (: ask_mizong :),
                "����" : "�����������Ե��ж����书��",
        ]));

        carry_object("/clone/weapon/panguanbi")->wield();
}

void init()
{
        add_action("do_sue", "sue");
}

int do_sue(string arg)
{
        object ob, obj, me = this_player();
        mapping sue, sue_site, sued;
        string my, your, *times, yourfam;
        int i, total, period;

        if( is_busy() || is_fighting() ) 
                return notify_fail("������æ�š�\n");

        if( !(ob = find_player(arg)) ) {
                ob = new(USER_OB);
                ob->set("id", arg);
                if( !ob->restore() ) {
                        command("say û������ˡ�");
                        destruct(ob);
                        return 1;
                }
                ob->set_temp("insue", 1);
                call_out("do_destroy", 1, ob);
        }

        yourfam = (string)ob->query("family/family_name");
        if( ob->query("sell_woman/" + me->query("id"))
        &&  (int)ob->query("combat_exp") > 100000
        &&  (  yourfam == "������"
            || yourfam == "������"
            || yourfam == "�䵱��"
            || yourfam == "��ɽ��"
            || yourfam == "�����μ�" ) ) {
                ob->delete("sell_woman/" + me->query("id"));
                ob->set("incharge", time());
                ob->save();
                command("nod");
                command("say �ҽ�ת������������������������");
                log_file("SuePK", sprintf("%s��%sʱ����%s������Ů\n", me->query("name"), ctime(time()), ob->query("name")));
                return 1;
         }

        if( me->query_temp("my_killer") != ob->query("id") ) {
                command("say ���" + ob->query("name") + "û���˺���ѽ��");
                return 1;
        }

        if( me->query_temp("pking/" + ob->query("id")) ) {
                command("say ���Լ����Ļ�������Թ���ˡ�");
                return 1;
        }

        if( (int)ob->query("combat_exp") < (int)me->query("combat_exp") ) {
                command("say ����˽�˶�Թ̫���ˣ��㻹����ǿ��Ϣ���");
                return 1;
        }

        if( (int)me->query("combat_exp") > 300000 ) {
                command("say ���Ѿ��������г����ˣ�������ǿ��Ϣ�ɡ�");           
                return 1;
	}

        start_busy(2);
        me->delete_temp("my_killer");

        my = me->query("id");
        your = ob->query("id");

        if( !mapp(sue = query("sue")) ) {
                sue = ([]);
                sue_site = ([]);
                sued = ([]);
        } else {
                if( !mapp(sue_site = query("sue_site")) ) sue_site = ([]);
                sued = query("sued");

                times = keys(sue);
                for(i = 0; i < sizeof(times); i++) {
                        if(time() > atoi(times[i]) + 86400) {
                                map_delete(sue, times[i]);
                                map_delete(sue_site, times[i]);
                                map_delete(sued, times[i]);
                        }
                }

                times = keys(sue);
                total = 0;
                for(i = 0; i < sizeof(times); i++) {
                        if( sue[times[i]] == my && sued[times[i]] == your ) {
                                command("say �㲻��ǰ�ո�����ˣ��������ڻ�û�е��������");
                                save();
                                return 1;
                        }

                        if( sue_site[times[i]] == query_ip_name(me) ) {
                                command("say ������Ѹո�����ˣ��������ڻ�û�е��������");
                                save();
                                return 1;
                        }

                        if( sued[times[i]] == your ) total++;
		}
        }

        command("nod");

        switch((string)ob->query("family/family_name")) {
	case "�䵱��" : period = 10; break;
	case "������" : period = 10; break;
        case "��ɽ��" : period = 15; break;
        case "������" : period = 15; break;
        case "�һ���" : period = 20; break;
        case "ؤ��"    : period = 20; break;
        case "����ɽׯ" : period = 30; break;
        case "������" : period = 30; break;
        default              : period = 25; break;
        }

        if( random(total) >= period/2 ) {
                command("say �ҽ�ת���䵱�������������������������������������������λ�����������ﴦ�����¡�");
                ob->set("incharge", time());
                ob->save();

                log_file("SuePK", sprintf("%s��%sʱ�浹%s\n", me->query("name"), ctime(time()), ob->query("name")));            

                for(i = 0; i < sizeof(times); i++) {
                        if( sued[times[i]] == your ) {
                log_file("SuePK", sprintf("%sҲ��%s��%s��%s���߹�\n", ob->query("name"), ctime(atoi(times[i])), sue[times[i]], sue_site[times[i]]));
                                map_delete(sue, times[i]);
                                map_delete(sue_site, times[i]);
                                map_delete(sued, times[i]);
                        }
                }
                save();

                if( ob->query_temp("insue") ) 
                        return 1;

                message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
                move("/d/wudang/xiaoyuan");
                message_vision("$N���˹�����\n", this_object());

                if( obj = present("zhang sanfeng", environment()) ) {
                        message_vision("$N��$n˵������������˱���������ֻ��" + ob->query("name") + "�������в�ɱ�޹������������˳��洦�����¡�\n", this_object(), obj);
                        message_vision("$N˵�����������䵱����֮�£����йٲ�ؿ�������������ȥ������\n", obj);

                        message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", obj);
                        obj->move(environment(ob));
                        message_vision(HIR"\n$N��$n�ȵ���" + RANK_D->query_rude(ob) + "��Ȼ��Σ�����֣�ʵ���������๼��\n"NOR, obj, ob);
                        obj->set_leader(ob);
                        obj->kill_ob(ob);
                }

                message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
                move("/d/taishan/daizong");
                message_vision("$N���˹�����\n", this_object());
                return 1;    
        }

        command("say �ȵ��������������������������档");
        set("sue/" + time(), my);
        set("sue_site/" + time(), query_ip_name(me));
        set("sued/" + time(), your);
        save();
        return 1;
}

int accept_object(object who, object ob)
{
        object room;
        int exp, p_exp, bonus, record, period;
        string my_id, file = base_name(ob);

        switch(file) {
        case JIAN:
                if( ob->query("my_killer") != who->query("id") )
                        return notify_fail("����ð�����£���Ҳ�ɣ���\n");

                if( (int)who->query("combat_exp") < 300000 )
                        return notify_fail("һ����ð���ɡ�\n");

                command("touch " + who->query("id"));
                command("say �����������о��ˣ�");

                period = time() - (int)who->query("shan/time4");
                if( period > 480 ) period = 480;
                if( period <  60 ) period =  60;

                bonus = (int)ob->query("bonus") * period / 600;
                record = bonus + random(bonus);
                who->add("combat_exp", record);

                who->set("shan/time4", time());
                log_file("test/ShanBonus", sprintf("%s��%sʱ�Ͻ���%s������%s�����\n", who->query("name"), ctime(time()), ob->name(), chinese_number(record)));
                call_out("do_destroy", 1, ob);
                return 1;

	case BANGYIN:
                my_id = who->query("id");
                if( ob->query("my_killer") != my_id )
                        return notify_fail("����ð�����£���Ҳ�ɣ���\n");

                if( !( room = find_object("/d/taishan/fengchan")) )
                        room = load_object("/d/taishan/fengchan");
                if( my_id == room->query("winner") )
                        return notify_fail(RANK_D->query_respect(who) + "�ǵ���������������ССһ���й����ܶ���˵�����ģ�");

                if( !( room = find_object("/d/taishan/xiayi")) )
                        room = load_object("/d/taishan/xiayi");
                if( my_id == room->query("winner") )
                        return notify_fail(RANK_D->query_respect(who) + "�ǵ���������������ССһ���й����ܶ���˵�����ģ�");

                if( !( room = find_object("/d/taishan/zhengqi")) )
                        room = load_object("/d/taishan/zhengqi");
                if( my_id == room->query("winner") )
                        return notify_fail(RANK_D->query_respect(who) + "�ǵ��񷣶�ʹ�ߣ���ССһ���й����ܶ���˵�����ģ�");

                exp = (int)ob->query("combat_exp");
                p_exp = (int)who->query("combat_exp");

                if( p_exp > exp + 1000 ) {
                        command("nod");
                        command("say �������˵��С��һ׮���ҾͲ������ˡ�");
                        call_out("do_destroy", 1, ob);
                        return 1;
                }

                command("thumb " + who->query("id"));
                if( (string)who->query("family/family_name") != "�䵱��" )
                        who->add("shen", exp / 100);

                bonus = 10 + 200 * exp / (exp + p_exp);

                record = bonus + random(bonus);
                who->add("combat_exp", record);

                log_file("test/ShanPlaying", sprintf("%s��%sʱ����%s����㣬�Ͻ���%s", who->query("name"), ctime(time()), chinese_number(record), ob->query("long")));
                call_out("do_destroy", 1, ob);
                return 1;
        }

        return notify_fail("����˵�����ⲻ������Ҫ�ġ�\n");
}

void do_destroy(object ob)
{
        destruct(ob);
}

// job1
string ask_bang(string name)
{
        object *obj, room;
        string *bangs, str, region, file;
        int i, temp;

        if( name == "��" ) 
                return "��������" + chinese_number(sizeof(info_bang)) + "��а������������ң���" + chinese_number(sizeof(empty_bangs)) + "����û�е����İ����ƹܡ�";

        if( name == "а��" ) {
                bangs = keys(info_bang);
                str = "������а���У�";
                temp = sizeof(bangs);
		for( i = 0; i < temp; i++ ) {
                        if( i != temp - 1 )
                                str += bangs[i] + "��";
                        else    str += bangs[i] + "��";
                }

                return str;
        }

        obj = filter_array(children(BANGZHU), (: clonep :));
        if( sizeof(obj) ) {
	        for(i = 0; i < sizeof(obj); i++) {
                        if( obj[i]->query("bangname") == name ) {
                                command("nod");
                                room = environment(obj[i]);
                                if( !room )
	                        return name + "����" + info_bang[name] + "���ʧ���ˡ�";

                                file = base_name(room);
                                if( strsrch(file, "/d/") != 0 
                                || !mapp(room->query("exits")) )
                                return name + "����" + info_bang[name] + "���ʧ���ˡ�";
				
                                region = explode(file, "/")[1];
                                return name + "����" + info_bang[name] + "�������" + region_names[region] + "һ������Ϊ������������";
                        }
                }
        }

        command(":)");
        return name + "����" + info_bang[name] + "��������ؼ͡�";
}

// job2
string ask_bangyin()
{
        object *obj, ob, me = this_player(), room;
        string *bangs, bang, myfam, my_id;
        int i;

        if( time() < (int)me->query("shan/time2") + 60 )
                return RANK_D->query_respect(me) + "���Ǹ����Ҵ�������\n";

        my_id = (string)me->query("id");
        if( !( room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");
        if( my_id == room->query("winner") )
                return RANK_D->query_respect(me) + "�ǵ���������������Ҳ̰��С��֮������";

        if( !( room = find_object("/d/taishan/xiayi")) )
                room = load_object("/d/taishan/xiayi");
        if( my_id == room->query("winner") )
                return RANK_D->query_respect(me) + "�ǵ�������ʹ�ߣ���Ҳ̰��С��֮������";

        if( !( room = find_object("/d/taishan/zhengqi")) )
                room = load_object("/d/taishan/zhengqi");
        if( my_id == room->query("winner") )
                return RANK_D->query_respect(me) + "�ǵ��񷣶�ʹ�ߣ���Ҳ̰��С��֮������";

        myfam = (string)me->query("family/family_name");
        if( (int)me->query("shen") < 10000
        &&   myfam != "������" )
                return RANK_D->query_respect(me) + "�Ǻڵ��ϵ��ˣ��Ϸ����ܷ��Ľ�һ��֮���и����㣿";

        if( (int)me->query("combat_exp") < 300000 )
                return RANK_D->query_respect(me) + "�����ڽ����϶�켸��ɡ�";

        if( (int)me->query("combat_exp") > 800000 )
                return RANK_D->query_respect(me) + "����������֣��α��������˻�ˮ��";

        if( myfam == "�����μ�" )
                return RANK_D->query_respect(me) + "�˴��������ϣ�����ԭ���ֲ�̫��Ϥ�ɡ�";

        if( myfam == "ؤ��" )
                return RANK_D->query_respect(me) + "����ؤ��β�Ϊؤ�ﾡ�ľ�����";

        if( myfam != "������"
        &&  myfam != "�䵱��"
        &&  myfam != "������"
        &&  myfam != "��ɽ��" )
                return RANK_D->query_respect(me) + "���������ɳ������Ϸ����ܷ��Ľ�һ��֮���и����㣿";

 //       if( present("bangyin", me) )
        if( stringp(me->query_temp("shan/bangzhu")) )
                return RANK_D->query_respect(me) + "���ϲ����Ѿ�����һ���ӡ����";
            
        obj = filter_array(children(BANGYIN2), (: clonep :));
        if( sizeof(obj) >= 3 )
                return "�������̫ƽ���£����´������ɡ�";

        bangs = empty_bangs;
        if( sizeof(obj) ) {
                for(i = 0; i < sizeof(obj); i++)
                        bangs -= ({obj[i]->query("bangname")});
        }
        bang = bangs[random(sizeof(bangs))];

        ob = new(BANGYIN2);
        ob->set("bangname", bang);
        ob->set("long", bang + ob->query("name") + "��\n");
        ob->set("owner", me->query("id"));
        ob->move(me);
        me->set_temp("shan/bangzhu", bang);

        message_vision("$N��" + bang + ob->query("name") + "������$n��\n", this_object(), me);
        command("congra");
        me->set_temp("apply/short",
                ({ bang + HIR"����"NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));

        log_file("test/ShanPlaying", sprintf("%s��%sʱ������%s����\n", me->query("name"), ctime(time()), bang));

        me->set("shan/time2", time());
        return "��" + RANK_D->query_respect(me) + "���ս�" + bang + "�ı��һ������֮�";
}

// job3
string ask_jianghu()
{
        object *obj, ob, me = this_player();
        string *places, place, my;
        int i, temp;

        if( time() < (int)me->query("shan/time3") + 120 )
                return RANK_D->query_respect(me) + "���Ǹ����Ҵ�������\n";

        if( (int)me->query("shen") < 100000
        &&  (string)me->query("family/family_name") != "������" )
                return RANK_D->query_respect(me) + "�Ǻڵ��ϵ��ˣ�ֻ��ħ����" + RANK_D->query_respect(me) + "�����ġ�";

        if( (int)me->query("combat_exp") < 500000 )
                return RANK_D->query_respect(me) + "�����ڽ����϶�켸��ɡ�";

        obj = filter_array(children("ZHANGLAO"), (: clonep :));
        if( (temp = sizeof(obj)) >= 3 )
                return RANK_D->query_respect(me) + "�ܷ�һЩ����ɨ��ħ��������";

        if( temp = sizeof(obj) ) {
                for(i = 0; i < sizeof(obj); i++) {
                        if( obj[i]->query("bj_victim") == me->query("id") )
                                return RANK_D->query_respect(me) + "Ҳ̫��������������ʿʧ���ˡ�";
                }
        }

        if( temp >= 3 )
                return RANK_D->query_respect(me) + "�ܷ�һЩ����ɨ��ħ��������";

        ob = new("/d/changbai/bj/zhanglao");
        ob->set("bj_victim", me->query("id"));
        places = keys(zl_places);
        place = places[random(sizeof(places))];
        ob->move(place);
        message("vision",
                ob->name() + "���˹�����\n",
                environment(ob), ({ob}));

        me->set("shan/time3", time());
        log_file("test/ShanPlaying", sprintf("%s��%sʱ��������%s\n", me->query("name"), ctime(time()), zl_places[place]));
        command("sigh");
        return "���ħ��ɦ��" + zl_places[place] + "����������������ð�����";
}


// job4
string ask_jian()
{
        object *obj, room, lama, ob = this_player();
        string place;
        int i, temp;

        if( (int)ob->query("combat_exp") < 500000 ) {
                command("shake " + ob->query("id"));
                return "����̫�����ѣ���������Ϊ��";
        }

        if( time() < (int)ob->query("shan/time4") + 60 )
                return RANK_D->query_respect(ob) + "���Ǹ����Ҵ�������\n";

        ob->set("shan/time4", time());

        obj = filter_array(children(LAMA), (: clonep :));

        if( temp = sizeof(obj) ) {
                for(i = 0; i < temp; i++) {
                        if( !(room = environment(obj[i])) ) {
                                destruct(obj[i]);
                                command("sigh");
                                return "�����š�����֮����ʧ���ˣ��ۿ���Ҫ������ͷ�ˡ�";
                        }

                        if( !mapp(room->query("exits")) 
                        ||  strsrch(base_name(room), "/d/") != 0 ) {
                                destruct(obj[i]);
                                command("sigh");
                                return "�����š�����֮����ʧ���ˣ��ۿ���Ҫ������ͷ�ˡ�";
                        }
                }

                command("shout");
                return "����ʢ�������š�����֮�����ѱ����ڸ�������";
        }

        place = lama_places[random(sizeof(lama_places))];
        lama = new(LAMA + "2");
        lama->move(place);
        message("vision",
                lama->name() + "���˹�����\n",
                environment(lama), ({lama}));

        lama = new(LAMA);
        lama->move(place);
        message("vision",
                lama->name() + "���˹�����\n",
                environment(lama), ({lama}));

        command("shout");
        return "����ʢ�������š�����֮�����ѱ����ڸ�������";
}


string ask_mizong()
{
        object ob, *obj, room;
        string file;

        obj = filter_array(children(LAMA), (: clonep :));

        if( !sizeof(obj) ) return "��Ҳ��֪�����������";

        ob = obj[random(sizeof(obj))];
        if( !(room = environment(ob)) ) {
                destruct(ob);
                return "��Ҳ��֪�����������";
        }

        if( strsrch((file = base_name(room)), "/d/") != 0 ) {
                destruct(ob);
                return "��Ҳ��֪�����������";
        }

        command("nod");
        return "�����ϴ��ţ�������ǳ�û��" + region_names[explode(file, "/")[1]] + "һ����";
}