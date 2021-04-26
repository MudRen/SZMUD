// Code of ShenZhou
// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object ob, man, *all, *inv;
    mapping fam, skl, lrn, map;
    string *sname, *mapped, giftName;
    int sp, dp;
    int i, j, cost;
    int gift;

    seteuid(getuid());

    all = all_inventory(environment(me));
    for(i=0; i<sizeof(all); i++) 
    {
        if( living(all[i]) && !userp(all[i]) && all[i]->query("race") == "����") 
        {
            man = all[i];
            break;
        }
    }
    if ( (!(fam = me->query("family")) || fam["family_name"] != "ؤ��") )
        return notify_fail("ֻ����ؤ���ܴ�̽���˵ļ��ܣ�\n");

    if ( !objectp(man) )
        return notify_fail("��Χû���ܰ���ȥ�˽���˵���Ϣ��\n");

    if ( me->query("rank") <= 1 )
        return notify_fail("��ֻ�Ǹ���������С��ؤ���Է��϶�ʲô����������㣡\n");

    if ( me->query_skill("checking",1) < 10 )
        return notify_fail("��Ĵ�̽������δ���죬�޷��˽���˵���Ϣ��\n");

    if ( !arg )
        return notify_fail("��Ҫ����˭����Ϣ��\n");
    if ( arg == "mariner" || arg == "buwu" ) return notify_fail("��Ҫ����˭����Ϣ��\n");

    if ( present(arg, environment(me)) )
        return notify_fail("��Ҫ�������˾��ڱ��ϣ��������ʲ����׵��ɣ�\n");

    ob = find_player(arg);
    if (!ob) ob = find_living(arg);
    if (!ob) return notify_fail("��Ҫ����˭����Ϣ��\n");

    if ( ob == me )
        return notify_fail("��û���᱿�ɣ�Ҫ���˸������Լ��������\n");

    cost = me->query("max_jing")/(me->query_skill("checking",1)/10) - 10;

    if ( me->query("jing") <= cost )
        return notify_fail("������̫���ˣ��޷�ȥ�������˵���Ϣ��\n");

    tell_object(me, "\n������ǰȥ��С���������" + man->name() + "��������" + ob->name() + "����� ...\n\n");
    message("vision", "ֻ��" + me->name() + "����Ц����" + man->name() + "˵�Ż��������ڴ���Щʲô��\n\n", 
        environment(me), ({ me, man }) );

    sp = me->query_skill("checking")*10 + me->query("kar")*5 + me->query("jing") + man->query("jing");
    dp = ob->query("kar")*5 + ob->query("jing")*2;
    
    if ( random(sp) < random(dp) )
        return notify_fail( man->name() + "ҡ��ҡͷ��˵���������ҿɲ������"
            + RANK_D->query_respect(me) + "����ȥ����˴���һ�°ɣ�\n");

    me->receive_damage("jing", cost );

    write( GRN + man->name() + "͵͵�����ظ����㣺 \n" NOR);

    skl = ob->query_skills();
    if(!sizeof(skl)) {
        write( ob->name() + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
        return 1;
    } else {
        sname  = keys(skl);
        i = random(sizeof(skl));
        write( ob->name() + "ѧ��" + chinese_number(skl[sname[i]]) + "����" + to_chinese(sname[i])+ "��\n");
    }   

    inv = all_inventory(ob);
    if( !sizeof(inv) ) {
        write(ob->name() + "����û��Я���κζ�����\n");
        return 1;
    } else {
        j = random(sizeof(inv));
        write( ob->name() + "���ϴ���" + inv[j]->short() + "��\n");
    }   
    dp = dp*3;
    cost = cost + ob->query("kar")*10;
    if ( me->query( "jing" ) > cost*2 && random( sp ) > random( dp ) )
    {
        switch( random( 4 ) )
        {
        case 0:
            giftName = "������\n";
            gift = ob->query( "str" );
            break;
        case 1:
            giftName = "���ԡ�\n";
            gift = ob->query( "int" );
            break;  
        case 3:
            giftName = "���ǡ�\n";
            gift = ob->query( "con" );
            break;  
        default:
            giftName = "����\n";
            gift = ob->query( "dex" );
            break;  
        }
        write( ob->name()+"��"+chinese_number( gift )+"������"+giftName );
        me->receive_damage("jing", cost*2 );
    }
    return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : check|dating [<ĳ��>]

���ָ������������������ѧ������Ϣ��

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills|cha ���Բ�֪�Է��ļ���״����

������Ϊؤ�����ר�ã�����ѧϰ��Ӧ�ļ��ܡ�

HELP
    );
    return 1;
}

