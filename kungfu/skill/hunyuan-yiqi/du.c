// Code of ShenZhou
// du.c 
// by aln 4 / 98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        mapping fam;
        string dest;

        mapping bank_bank = ([
                "/d/shaolin/hanshui1" : "/d/shaolin/hanshui2",
                "/d/shaolin/hanshui2" : "/d/shaolin/hanshui1",
                "/d/xixia/oldwall"    : "/d/xixia/xhbao",
                "/d/xixia/xhbao"      : "/d/xixia/oldwall",
                "/d/taihu/taihu"      : "/d/taihu/matou",
                "/d/taihu/matou"      : "/d/taihu/taihu",
        ]);

        fam = me->query("family");
        if( fam["family_name"] != "������" || fam["generation"] != 35 )
        return notify_fail("�㲻�����ֶ��ֱ���ɮ����ʹ��һέ�ɽ�����\n");

        if( me->query_skill("shaolin-shenfa", 1) < 200 )
        return notify_fail("��������������������޷�ʩչһέ�ɽ�������\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 160 )
        return notify_fail("��Ļ�Ԫһ���������������޷�ʩչһέ�ɽ�������\n");

        if( me->query_skill_mapped("dodge") != "shaolin-shenfa" )
        return notify_fail("������û��ʹ����������Ϊ�Ṧ�ĵ����⼼�ܡ�\n");

        if( me->query("max_neili") < 2000 || me->query("neili") < 1000 )
        return notify_fail("��������������޷�ʩչһέ�ɽ�������\n");

        if( undefinedp(dest = bank_bank[base_name(environment(me))]) )
        return notify_fail("�˵ز��ʺ�ʩչһέ�ɽ�������\n");

        message_vision("\n$Nʰ�𰶱ߵ�һ֦«έ��Ͷ�벨�ι�����ˮ�档\n" +
        "����$NһԾ���𣬽ż���έ֦��һ�㣬����ƮƮ����һ�����ˮ���ϴ��˹�ȥ��\n\n", me);

        me->add("neili", - (100 + random(200)));
        me->move(dest);
        return 1;
}
