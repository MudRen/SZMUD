inherit ITEM;
#include "/clone/misc/site.h"
#include <ansi.h>
string look_map();
void create()
{
        set_name(HIW"Ǭ����ͼ"NOR, ({ "newbie maps","trans map", "qkdt", "maps", "ditu"}) );
        set_weight(500);
        set("no_drop","�������Է��ļһ��ô�����أ�\n");
        set("no_get", 1);  
        set("no_steal", 1);  
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "\n����һ�š� ���� ���ĵ�ͼ��ר������ʹ�á�\n�����ڿ���������������("HIW"trans"NOR")����һЩ���õ�����("HIW"look area"NOR")��\n�������ˣ�����ҧ("HIW"full"NOR")һ�����ŵ�ͼ����ʳ�����ˮ��\nҪ���㻹�����������׵ģ������� newbie ����("HIW"newbie"NOR")��\n");
                set("unit", "��");
        }
        setup();
}
void init()
{
        object me = this_player();
        if ( !me->is_ghost() ) {
        add_action("do_look","look");
        add_action("do_trans","trans");
        add_action("do_full","full");
        }
}
int do_trans(string arg)
{
        object me,room,ob,*obj;
        string msg;
        int i;
        me=this_player();
        
        if( ! environment()->is_character() ) return 0;
        if (me->query("job/description") == "����ɽ��" && objectp(present("zhike daozhang", environment(me))))
               return notify_fail(HIG"\n�㲻������ݹ���������������˾��ȷ����ɣ�\n"NOR);

        if (me->query("age") >= 18)
                return notify_fail("����ô���˻�����ʶ·��\n");

        if (me->query("combat_exp") >= 40000)
                return notify_fail("��������Ҳ�����ˣ�������ʶ·��\n");
                
        if( !arg ) return notify_fail("��Ҫȥ���\n");
        
        if (me->is_fighting())
                return notify_fail("����ô�ߣ�û��ô���װɣ�\n");

        if  (!environment(me)->query("outdoors"))
                return notify_fail("��������ô�ҷ��򣿵������ȥ���԰ɡ�\n");

/*      if ( me->query("family/family_name"))
        {
                if (arg != mp[me->query("family/family_name")]["ID"] && !stringp(city[arg]))
                        return notify_fail("��Ҫȥ���\n");               
        }else */
        if (!stringp(places[arg]))
                return notify_fail("��Ҫȥ���\n");

        ob=first_inventory(me);

        while(ob){
        if (ob->is_character() && !ob->is_corpse() )
                return notify_fail("�㲻�ܴ�"+ob->name()+"����һ���ߣ�\n");
        ob=next_inventory(ob);
        }
        if( stringp(msg = me->query("env/msg_mout")) )
                {if (msg!="") message_vision(msg+"\n", me);}
        else
                message_vision("\n�Ҵ�ææ���ܹ���һ�����ְ������顣\n"CYN"���ְ�������һ��ץס$N���֣�һת�۱㲻���ˡ�\n\n"NOR, me);
        if (!room=find_object(places[arg]) )
                room=load_object(places[arg]);
        me->move(room);
        if( stringp(msg = me->query("env/msg_min")) )
                {if (msg!="") message_vision(msg+"\n", me);}
        else
                message_vision(CYN"\n���ְ��������$N˵�����뵽�ľ�������ɣ��Ժ�Ҫ�ǵ�·Ŷ��\n"NOR"���ְ�������˵�꣬�㼱�Ҵҵ��뿪�ˡ�\n\n", me);

        me->receive_damage("jingli", 10);
                if(me->query("potential") > 10) me->add("potential", -random(3)); 
                else me->receive_damage("jing", 10);
        return 1;
}
int do_full()
{
        int max;
        object me = this_player(); 

        if (me->query("age") >= 16)
                return notify_fail("����ô����С����һ����\n");

        if (me->query("combat_exp") >= 6000)
                return notify_fail("������Ӧ�ÿ��������ˡ�\n");

        if (me->query("food") < me->max_food_capacity() / 3
            || me->query("water") < me->max_water_capacity() / 3)
        {
                max = me->max_food_capacity();
                me->set("food",max);
                max = me->max_water_capacity();  
                me->set("water",max);
                tell_object(me,RED"��������죬ҧ�˼��ڵ�ͼ�ı߽ǣ���ʱ�о��ö��ˣ�\n"NOR);
                return 1;
        }else{
                tell_object(me,CYN"�����ڲ��Ǻܶ����������ŵ�ͼ�����԰ɣ�\n"NOR);
                return 1;
        }
}
int do_look(string arg)
{
        object me = this_player();
        object ob = this_object();
        string mpn, msg = "";
        string *cityx, *mpx;
        int i, cnt = 0;
        mpn = me->query("family/family_name");

        if (!arg || arg != "area")return 0;
        if (me && present(ob, me))
        {
/*              if (me->query("family/family_name"))
                {
                        msg += "\n�����ڿ���������������(trans)����һЩ�ط���\n\n     ";
                        cityx = keys(city);
                        for (i=0; i<sizeof(cityx); i++) {
                                msg = sprintf("%s"HIM"%-2s"NOR" : "HIG"%-12s"NOR"%s", msg, cityx[i], city[cityx[i]], (cnt%3==2? "\n     ": ""));
                                cnt ++;
                        }
                        if (mpn != "����μ�")
                                msg += HIY+mp[mpn]["ID"]+NOR+" : "+HIC+mp[mpn]["NAME"]+NOR;
                }else{*/
                        msg += "\n�����������������(trans)����һЩ�ط���\n\n     ";
                        cityx = keys(city);
                        for (i=0; i<sizeof(cityx); i++) {
                                msg = sprintf("%s"HIM"%-2s"NOR" : "HIG"%-12s"NOR"%s", msg, cityx[i], city[cityx[i]], (cnt%3==2? "\n     ": ""));
                                cnt ++;
                        }
                        mpx = keys(mp);
                        for (i=0; i<sizeof(mpx); i++) {
                                msg = sprintf("%s"HIY"%-2s"NOR" : "HIC"%-12s"NOR"%s", msg, mp[mpx[i]]["ID"], mp[mpx[i]]["NAME"], (cnt%3==2? "\n     ": ""));
                                cnt ++;
                        }
//              }
        }
        tell_object(me,msg+"\n");
        return 1;
}
void owner_is_killed() { destruct(this_object()); }
