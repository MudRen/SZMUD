#include <ansi.h>
string give_gift();
mixed *story = 
({
        "ĳ�챿���������ݳ��ڣ��������������ޣ���Ȼ������һ��ɧ��",
        "ĳ�ˣ���������Ұ��ɽ������ɽ������ҿ��ܰ�������",
        "û�ȱ�����Ӧ������һ�������Ѿ��ܵ�����ǰ��������ϵ�����",
        "���ˣ���������������ֵǮ�Ķ�����������",
        "������������ȣ��������û��һ�����ˣ�����ľ��⣬�ܵı��򻹿졣",
        "û�취�����ŵ��Ѿ�������ǰ�غ󱳣�����Σ������",
        "����㣡m d����үûʱ�����ĥ�䣡������ͷ�Ӵ�С�",
        "�������ٺ١��ؼ�Ц���������������ң�˭��˭ѽ����",
        "ֻ�������߾�˫�֣���ȣ���ȥ����!��, ֻ������һ�����������",
        "�������ױ�������������ŵ��ϱ�ȥ����",
        (: give_gift :),
        "����",
        "������������",
        "����ͷ�����˰��Σ��ƿڴ����n n d������һ����ʲô��Ϸ����",
        "��������һ�ݣ������ˣ������ˣ������ʮ���ƣ�Ω���ϼơ�����",
        "���Ǳ���Ѹ�ټ��롰home������",
        "ֻ��һ���������ᣬ��������Ӱ�Ѿ������ˡ�",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        
        int i;
        object env,ob;
        object *players;
        string msg;

        players = users();
        if (sizeof(players) >= 5)
        {
                for (i = 0; i < 5; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->is_fighting()) continue;
                        if (!environment(ob)) continue;
                        if (ob->query_temp("netdead")) continue;                               
                }
                if(!ob) return "";
               tell_object(ob,HIW"һ���¡¡�����������һ����������������ƫ����\n"
                		"���ҵ���ͷ�ϣ����ʱ�����˹�ȥ����\n\n" NOR);
                tell_object(ob,"������������о��Լ����������Ӿ�տ��!\n");
                ob->unconcious();
                ob->add("max_neili",10 + random(30));
                msg=HIW"���Ͻ���һ�����磬��"+ob->name()+"������.......\n"NOR;
                env=environment(ob);
                if (objectp(env))
                        tell_room(env, msg);
        }
        CHANNEL_D->do_channel( this_object(),"rumor",HIM"�������˱�����������....................\n"NOR);
        return HIM "�������˱�����������....................\n" NOR;
}