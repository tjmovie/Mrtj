#pragma once

#include "weapon_csbase.h"

#if defined(CLIENT_DLL)
#define CKnife C_Knife
#endif

// ----------------------------------------------------------------------------- //
// CKnife class definition.
// ----------------------------------------------------------------------------- //

class CKnife : public CWeaponCSBase
{
  public:
    DECLARE_CLASS(CKnife, CWeaponCSBase);
    DECLARE_NETWORKCLASS();
    DECLARE_PREDICTABLE();

#ifndef CLIENT_DLL
    DECLARE_DATADESC();
#endif

    CKnife();

    // We say yes to this so the weapon system lets us switch to it.
    bool HasPrimaryAmmo() OVERRIDE;
    bool CanBeSelected() OVERRIDE;

    void Precache() OVERRIDE;

    void Spawn() OVERRIDE;
    void Smack();
    bool SwingOrStab(bool bStab);
    void DoAttack(bool bIsSecondary);
    void PrimaryAttack() OVERRIDE;
    void SecondaryAttack() OVERRIDE;

    void ItemPostFrame(void) OVERRIDE;

    bool Deploy() OVERRIDE;
    void Holster(int skiplocal = 0);
    bool CanDrop();

    void WeaponIdle() OVERRIDE;

    CSWeaponID GetWeaponID(void) const OVERRIDE { return WEAPON_KNIFE; }

  public:
    trace_t m_trHit;
    EHANDLE m_pTraceHitEnt;

    CNetworkVar(float, m_flSmackTime);
    bool m_bStab;

  private:
    CKnife(const CKnife &) {}
};